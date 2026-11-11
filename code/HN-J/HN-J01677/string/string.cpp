#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int l;
int cnt=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u;
		char x;
		l+=u;
		cin>>u>>x;
		for(int j=1;j<=u;j++)
		{
			s+=x;
		}
	}
	for(int i=0;i<(l+1)/2;i++)
	{
		if(s[i]!=s[l-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
