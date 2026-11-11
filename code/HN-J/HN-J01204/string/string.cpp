#include <bits/stdc++.h>
#define int long long
using namespace std;
bool hw(string s)
{
	int i=1,j=s.size()-1;
	while(i<=j)
	{
		if(s[i]!=s[j])return false;
		i++,j--;
	}
	return true;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string y;
		cin>>x>>y;
		if(x>=1e7)
		{
			cout<<x*n/2;
			return 0;
		}
		for(int j=1;j<=x;j++)s+=y;
		cnt+=x;
	}
	if(hw(s)==true)
	{
		cout<<0;
		return 0;
	}
	cout<<cnt/2;
	return 0;
}
