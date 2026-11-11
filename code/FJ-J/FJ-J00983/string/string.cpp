#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

struct node
{
	int a;
	char c;
}g[N<<1];

int n;
int ans=0;
string as,t;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>g[i].a>>g[i].c;
		ans+=g[i].a;
		for(int j=1;j<=g[i].a;j++)
		{
			as+=g[i].c;
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=g[i].a;j++)
		{
			t+=g[i].c;
		}
	}
	int len=as.size();
	for(int i=0;i<len;i++)
	{
		if(as[i]==t[i])
		{
			ans--;
		}
	}
	cout<<ans/2<<"\n";
}
