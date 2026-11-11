#include<bits/stdc++.h>
using namespace std;
#define ll long long
int opt,T,n;
ll m,x[2000006];
template<typename T>
int rf(T f[],T fs,int l,int r)
{
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(f[mid]<=fs)l=mid;
		else r=mid-1;
	}
	return l;
}int ans;
void Ans(int l,int r)
{
	++ans;
	if(1<l&&x[l+1]-x[l-1]>m&&x[l]-x[l-1]<=m)
	{++ans,--l;
		while(1<l&&x[l+2]-x[l-1]>m&&x[l]-x[l-1]<=m)--l,++ans;
	}
	if(r<n&&x[r+1]-x[r-1]>m&&x[r+1]-x[r]<=m)
	{++ans,++r;
		while(r<n&&x[r+1]-x[r-2]>m&&x[r+1]-x[r]<=m)++r,++ans;
	}
}
bool sf(int y)
{
//	if(y+3<=n&&x[y+2]-x[y]<=m&&x[y+3]-x[y+1]<=m&&x[y+3]-x[y]>m)Ans(y,y+3);
	int f1=rf(x,x[y]+m,y,n);
	int f2=rf(x,x[f1-1]+m,f1-1,n);
	int n1=rf(x,x[f1-2]+m,f1-2,n);
	for(int i=n1+1;i<=f2;i++)
		Ans(y,i);//,cerr<<y<<":"<<i<<"\n";
	return 0;
}
int main()
{x[0]=-LLONG_MAX/2;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&opt,&T);
	while(T--)
	{ans=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)
		{
			sf(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
ans=3

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5




*///
