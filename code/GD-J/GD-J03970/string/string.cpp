#include<bits/stdc++.h>
using namespace std;
int main()
{ 
	
	int n;
	long long s[100005];
	string c[100005],b[90000005];
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i] >> c[i]; 
	}
	long long sum = 0,num = 0;
	for (int i = 1;i <= n;i++)
	{
		sum += s[i];
	}
	int k = 1; 
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= s[i];j++)
		{
			b[k] = c[i];
			k++;
		}
	}
	if (sum % 2 == 0)
	{
		int t = 1;
		for (int i = sum / 2 + 1;i <= sum;i++)
		{
			if (b[i] != b[i - t])
			{
				num++;
			}
			t += 2;
		}
	}
	else
	{
		int t = 2;
		for (int i = (sum + 1) / 2 + 1;i <= sum;i++)
		{
			if (b[i] != b[i - t])
			{
				num ++;
			}
			t += 2;
		}
	}
	cout << num;
	return 0; 
}
