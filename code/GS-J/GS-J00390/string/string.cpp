#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, midindex;
	cin >> n;
	long long nums[n+1], sums[n+1], midnum, left[n+1], right[n+1], t1 = 0,t2 = 0, total = 0, temp = 0, j = 0;
	char chars[n+1], midchar, leftchars[n+1], rightchars[n+1]; 
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i] >> chars[i];
		if(i == 0) sums[i] = nums[i];
		else sums[i] = sums[i - 1]+ nums[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (sums[i] > sums[n - 1] / 2)
		{
			midchar = chars[i];
			 midnum = nums[i];
			 midindex = i;
			 break;
		}
		left[i]= nums[i];
		leftchars[i] = chars[i];
	}
	
	left[midindex] = sums[n - 1] / 2 - sums[midindex - 1];
	leftchars[midindex] = midchar;
	
	for (int i = n - 1; i > midindex; i--)
	{
		
		right[n - i - 1]= nums[i];
		rightchars[n - i - 1] = chars[i];
	}
	
	right[n - midindex - 1] = midnum -(sums[n - 1] / 2 - sums[midindex - 1]);
	rightchars[n - midindex - 1] = midchar;
	
	for (int i = 0; i < midindex + 1; i++)
	{
		temp += left[i];
	}
	for (int i = 0; i < midindex + 1; i++)
	{
		while(left[i] > right[j])
		{
			if (leftchars[i] == rightchars[j]) total += right[j];
			left[i] -= right[j];
			right[j] = 0;
			j++;
		}
		if (left[i] == right[j])
		{
			if (leftchars[i] == rightchars[j]) total += right[j];
			left[i] = 0;
			right[j] = 0;
			j++;
		}
		if (left[i] < right[j])
		{
			if (leftchars[i] == rightchars[j]) total += left[i];
			right[j] -= left[i];
			left[i] = 0;
		}	
	}
	
	cout << temp - total;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

