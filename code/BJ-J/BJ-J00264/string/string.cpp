#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		int t; char c;
		cin>>t;
		cin>>c;
		for(int i=1;i<=t;i++)
		{
			s=c+s;
		}
	}
	int cnt=0;
	int gumu=s.size();
	for(int i=0;i*2<s.size();i++)
	{
		if(s[gumu-i-1]!=s[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
/*
 * 1-12,17-18 ac
 * ath : re/tle
 */
