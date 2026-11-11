#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int f1[500010][30],f2[500010][30];
int d[510][510],a[500010],s[500010];
constexpr int what=0;
void re(int& x)
{
	if(what==1)
	{
		cin>>x;
		return;
	}
	char c=getchar_unlocked ();
	while(c<'0'||c>'9')
		c=getchar_unlocked ();
	x=0;
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar_unlocked ();
	}	
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	if(what==1)
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);		
	}
	int n,m,q,u,o,p;
	re(u);re(n);re(m);re(u);re(q);
	for(int i=1;i<=m;i++)
		re(a[i]);
	for(int i=1;i<=n;i++)
	{
		re(u);
		for(int j=1;j<=u;j++)
		{
			re(o);re(p);
			f1[o][++s[o]]=i;
			f2[o][s[o]]=p;
		}
	}
	memset(d,127/3,sizeof(d));
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=s[i];j++)
			for(int k=j+1;k<=s[i];k++)
				d[f1[i][j]][f1[i][k]]=d[f1[i][k]][f1[i][j]]=min(d[f1[i][j]][f1[i][k]],f2[i][j]+f2[i][k]);	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	for(int i=1;i<=q;i++)
	{
		re(u);re(o);
		int Min=2e18;
		for(int j=1;j<=s[u];j++)
			for(int k=1;k<=s[o];k++)
				Min=min(Min,d[f1[u][j]][f1[o][k]]+f2[u][j]+f2[o][k]+a[u]+a[o]);
		cout<<Min<<'\n';
	}
	return 0;
}
