#include<bits/stdc++.h> 
using namespace std;
const int maxn=5*1e5+10;
struct S{
	long long a,t;
}s[1000][1000];
long long n,c,m,d,q,w[maxn],k[maxn],ans,tmp; 

long long minn(long long x1,long long x2)
{
	ans+=w[x1]+w[x2];
		for(long long j=1;j<=k[1];j++)
		{
			ans+=s[1][j].t;
		}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			
			scanf("%lld%lld",&s[i][j].a,&s[i][j].t);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x1,x2;
		cin>>x1>>x2;
		cout<<minn(x1,x2);	
 	} 
}
