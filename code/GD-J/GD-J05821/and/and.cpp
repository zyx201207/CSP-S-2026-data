#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ans=0;
	long long t=0;
	cin >> n >> m;
	int a[n];
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for (int i=0;i<n;i++)
	{
		t=a[i];
		for (int j=1;j<=m-1;j++)
		{
			t=t^a[j];
		}
		if (t>ans){ans=t;}
	}
	cout << ans;
	return 0;
} 
