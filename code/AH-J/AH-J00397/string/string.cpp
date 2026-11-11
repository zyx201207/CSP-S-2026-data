#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t1;
		char t2;
		cin>>t1>>t2;
		for(int i=1;i<=t1;i++)
		{
			s+=t2;
		}
	}
	int l=0,r=s.size()-1,ans=0;
	while(l<r)
	{	
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
