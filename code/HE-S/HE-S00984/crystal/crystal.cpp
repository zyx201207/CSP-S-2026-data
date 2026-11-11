#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],maxn=-1,minn=1e9;
struct node{
	int x,s;
}c[500005];
bool cmp(node q,node p)
{
	return q.s<p.s;
}
int n,ans,nm;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=false,vis=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1)
		{
			f=true;
		}
		if(a[i]!=a[i-1]+1&&i!=1)
		{
			vis=true; 
		}
		maxn=max(a[i]+m,maxn);
		minn=min(a[i],minn);
	}
	long long lm=m;
	if(!f)cout<<m;
	else if(!vis)
	{
		for(int i=0;i<=n;i++)
		{
			if(lm>=i)
			{
				lm-=i;
				ans++;
			}
		}
		cout<<ans;
	}
	else 
	{
		for(int i=minn;i<=maxn;i++)
		{
			int lm=m;
			nm=0;
			int now[500005];
			memset(c,0x6f,sizeof(c));
			for(int j=1;j<=n;j++)
			{
				c[j].s=i-a[j];
				c[j].x=j;
			}
			sort(c+1,c+1+n,cmp);
			int j=1;
			while(c[j].s<0&&j<=n)j++;
			for(int k=j;k<=n;k++)
			{
				if(lm>=abs(c[k].s)&&a[c[k].x]<=i)
				{
					lm-=c[k].s;
					nm++;
				}
			}
			ans=max(ans,nm);
		}
		cout<<ans;
	}
	return 0;
} 

