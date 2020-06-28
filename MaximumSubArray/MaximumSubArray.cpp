// MaximumSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> nums) {
    int sum = 0, mss = 0, i = 0, nmax = INT_MIN;
    bool allnegative = true;

    while (i < nums.size()) {
        if (nums[i] < 0) {
            if (nums[i] > nmax) {
                nmax = nums[i];
            }
        }
        else {
            allnegative = false;
            break;
        }
        i++;
    }
    if (!allnegative) {
        for (auto num : nums)
        {
            sum += num;
            if (sum < 0)
                sum = 0;
            if (sum > mss)
                mss = sum;
        }
    }
    else {
        return nmax;
    }
    return mss;
    
}

int main()
{
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    int max = maxSubArray(nums);
    cout << "mss: "<<max;

    getchar();
    return 0;
}
