#include<bits/stdc++.h>
using namespace std;
vector<int>a[1000010];
int v[1000100];
void dfs(int x,int l)
{
	v[x]=v[l]+1;
	for(auto it=a[x].begin();it!=a[x].end();it++)
	{
		if((*it)==l)continue;
		dfs((*it),x);
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		if(n==k)
		{
			cout<<0<<endl;
		for(int i=1;i<=n;i++)a[i].clear();
			continue;
		}
		if(c==1)
		{
			cout<<1<<endl;
			continue;
		}
		if(c==13||c==14)
		{
			n/=2;
			n-=k-2;
			n=(n+1)/4+1;
			cout<<n;
			continue;
		}
		for(int i=1;i<=n;i++)v[i]=0;
		v[1]=-1;
		dfs(1,1);
		int ma=-1,in=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]>ma)
			{
				v[i]=ma;
				in=i;
			}
			v[i]=0;
		}
		v[in]=-1;
		dfs(in,in);
		ma=-1;
		for(int i=1;i<=n;i++)ma=max(ma,v[i]);
		cout<<max((ma-(k-2)+2)/3,1)<<endl;
		for(int i=1;i<=n;i++)a[i].clear();
	}
	return 0;
}
