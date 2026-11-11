#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,sum,ans;
bool flag;
struct node{
	long long data;
	long long cnt;
	long long st[64];
}a[200009];
void jz(long long x,long long cur,long long cnt)
{
	if(x==1||x==0)
	{
		a[cur].st[cnt]=x;
		return ;
	}
	a[cur].st[cnt]=x%2;
	cnt++;
	jz(x/2,cur,cnt);
}
bool cmp(node x,node y)
{
	return x.cnt>y.cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].data);
		if(a[i].data-1!=a[i-1].data&&i!=1)flag=1;
		jz(a[i].data,i,0);
	}
	if(!flag)
	{
		ans=a[n].data;
		for(i=n-1;i>=n-m+1;i--)
		ans=ans&a[i].data;
		printf("%lld",ans);
	}
	else
	{
		for(i=0;i<64;i++)
		{
			sum=0;
			for(j=1;j<=n;j++)
				if(a[j].st[i]==1)sum++;
			for(j=1;j<=n;j++)
				if(a[j].st[i]==1)a[j].cnt+=sum;
		}
		//cout<<"\n";
		sort(a+1,a+1+n,cmp);
		ans=a[1].data;
		//printf("%lld %lld\n",ans,a[1].data);
		for(i=2;i<=m;i++)
		{
			ans=ans&a[i].data;
		//printf("%lld %lld\n",ans,a[i].data);
		}
		printf("%lld",ans);
		//printf("%lld %lld\n",a[i].data,a[i].cnt);
	}
	return 0;
}
/*
5 3
31 3 1 15 7

*/

