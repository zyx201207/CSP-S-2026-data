#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,p,ans=0;
char ch;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>ch;
		for(int j=1;j<=p;j++)
		{
			s+=ch;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
