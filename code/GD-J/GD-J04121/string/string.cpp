#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long a[20005];
	long long max;
	char c[200005];
	long long num[26];
	long long cg=0;
	int half = n/2;
	for(int i =0;i<n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for(int j = 0;j<n;j++)
	{
		int ai = a[j];
		int ci = c[j];
		if(num[ci-97]<ai)
		{
			num[ci-97] = ai;
		}
	}
	for(int i = 0;i<half;i++)
	{
		for(int j = n-i-1;j<n-i;j++)
		{
			if(c[i]!=c[j])
			{
				cg++;
			}
		}
	}
	for(int v = 0;v<26;v++)
	{
		if(v==0)
		{
			max = num[v];
			continue;
		}
		if(num[v]>max)
		{
			max = num[v];
		}
	}
	cout << max*cg;
	return 0;
} 
