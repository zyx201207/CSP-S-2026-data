#include<bits/stdc++.h>
using namespace std;
int n,m,ans,maxn;
int wl[40][211000];
int sz[211000];
int noo[211000];
int anns[40];
long long anss;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ans=n;
	for(int i=1;i<=n;i++)
	{
	long long o=1,a;
	cin>>a;
	while(a!=0)
	{
		wl[o][i]=a%2;
		a/=2;
		o++;
	}
	sz[i]=o-1;
	maxn=max(maxn,sz[i]);
	}
	for(int i=maxn;i>=1;i--)
	{
		int o=0,oo=0;
		for(int j=1;j<=n;j++)
		if(wl[i][j]==1&&noo[j]==0)
		o++;
		for(int j=1;j<=n;j++)
		if(wl[i][j]==1||noo[j]==1)
		oo++;
		if(o>=m&&ans-n+oo>=m)
		{
		anns[i]=1;
		for(int j=1;j<=n;j++)
		if(wl[i][j]==0&&noo[j]==0)
		noo[j]=1,ans--;
		}
		else
		anns[i]=0;
	}
	for(int i=1;i<=maxn;i++)
	{
	anss+=anns[i]*pow(2,i-1);
	}
	cout<<anss;
}