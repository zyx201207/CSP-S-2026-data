#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	char c[n];
	for(int i = 0;i<n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int cnt = 0;
	vector<char> b;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<a[i];j++)
		{
			b.push_back(c[i]);
		}
	}
	if(b.size() % 2 == 0)
	{
		for(int i = 0;i<b.size()/2;i++)
		{
			if(b[i] != b[n-1-i])
			{
				cnt++;
			}
		}
	}
	else
	{
		for(int i = 0;i<=b.size()/2;i++)
		{
			if(b[i] != b[n-1-i])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
