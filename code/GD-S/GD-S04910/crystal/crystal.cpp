#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m;
const int MAXN=500007;
long long sj[MAXN];
long long tx[MAXN];//¥¶¿Ì 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&sj[i]);
	}
	sort(sj+1,sj+1+n);
	for(int i=2;i<=n;i++)
	{
		tx[i]=tx[i-1]+(sj[i]-sj[i-1])*(i-1);
	}
	for(int i=2;i<=n;i++)
	{
		if(tx[i]>m)
		{
			printf("%d",i-1);
			return 0;
		}
	}
}
