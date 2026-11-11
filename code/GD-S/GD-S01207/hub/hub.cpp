#include<bits/stdc++.h>
using namespace std;
int C,T,n,K,l,r,mid,d[2000005],dd[2000005],u1[2000005],u2[2000005],d1,d2,h[2000005];
struct bian{int n,d;}b[4000005];
void hello(int x,int y)
{
	d[x]=dd[x]=d[y]+1;
	for(int i=h[x];i;i=b[i].n)
	{
		if(b[i].d==y)continue;
		hello(b[i].d,x);
		dd[x]=max(dd[x],dd[b[i].d]);
	}
	if(!d1&&dd[x]-d[x]==mid)d1=x;
}
void hey(int x,int y)
{
	u1[x]=u1[y]+1;
	for(int i=h[x];i;i=b[i].n)
	{
		if(b[i].d==y)continue;
		hey(b[i].d,x);
	}
}
int hi()
{
	d1=0;
	hello(1,1);
	if(!d1)return 1;
	d2=d1,d1=0;
	hello(d2,d2);
	u1[d1]=-1;
	hey(d1,d1);
	for(int i=1;i<=n;i++)u2[i]=u1[i];
	u1[d2]=-1;
	hey(d2,d2);
	int s=0;
	for(int i=1;i<=n;i++)s+=max(min(u1[i],u2[i])-mid,0);
	return s<=K;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>K;
		for(int i=1;i<=n;i++)h[i]=0;
		for(int i=1,x,y;i<n;i++)
		{
			cin>>x>>y;
			b[i]={h[x],y},h[x]=i;
			b[i+n]={h[y],x},h[y]=i+n;
		}
		l=0,r=(n+1)>>1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(hi())r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
