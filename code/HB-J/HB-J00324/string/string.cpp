#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		int x;
		string y;
		cin>>x>>y;
		for(int j=0;j<x;j++)
		{
			s+=y;
		}
	}
	int t=s.size()/2;
	if(s.size()%2==1)
	{
		t++;
	}
	for(int i=0;i<t;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
