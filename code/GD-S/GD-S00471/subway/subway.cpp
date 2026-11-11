#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int u,v;
int minans=999;
int w[500005];
int k[505];
int a[505][25],t[505][25];
int q1[100005],q2[100005];
int find(int i,int j)
{
	for(int l=1;l<=k[i];l++)
	{
		if(a[i][l] == j) return l;
	}
	return 0;
} 


int dfs(int ans,int i,int j,int floor)
{
	int tar;
	
	tar=find(i,v);
	if(tar>0)
	{
		ans+=t[i][j];
		ans+=t[i][tar];
		if(floor==1)
		{
			minans=ans;
			return 0;
		}
		return ans;
	}
	else 
	{
		for(int ll=1;ll<=k[i];ll++)
		{
			if(ll != j)
			{
				int minnumber=999;
				for(int lll=1;lll<=n;lll++)
				{
					if(lll==i) continue;
					int num = find( lll , a[i][ll] );
					if( num > 0)
					{
						int number = dfs(ans+t[i][j]+t[i][ll] , lll , num , floor+1);
						if(floor==1)
						{
							ans+=number;
							minans=min( ans , minans );
							ans-=number;
						}
						else
						{
							minnumber = min(minnumber,number);
						}
					}	
				}
				return minnumber;
			} 
		}
		return 0;
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q1[i]>>q2[i];
	}
	for(int o=1;o<=q;o++)
	{
		minans=999;
		u=q1[o];
		v=q2[o];
		for(int i=1;i<=n;i++)
		{
			if(find(i,u)>0) 
			{
				dfs(0,i,find(i,u),1);
			}
		}
		cout<<w[u]+w[v]+minans<<endl;
	}
	return 0;
}
