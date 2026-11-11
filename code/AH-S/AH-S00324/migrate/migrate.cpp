#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,s,ans,minn[15][15],p,q;
long long a[2000005];
map<int ,int> mp;
void dfs(long long step,long long x,long long y)
{
	if(x==y) 
	{
		minn[p][q]=min(minn[p][q],step);
		return ;
	}
	for(int i=x+1;i<=min(x+d,y);i++)
	{
		/*if(mp[i]==1)*/ dfs(step+1,i,y);
	}
}
void dfs2(long long step,long long x,long long y)
{
	if(x==y) 
	{
		if(step==minn[p][q]) s++;
		return ;
	}
	for(int i=x+1;i<=min(x+d,y);i++)
	{
		if(mp[i]==1) dfs2(step+1,i,y);
	}
}
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		ans=0;
		memset(minn,0x3f,sizeof(minn));
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			mp[a[i]]=1;
		}
		//for(int i=-5;i<=5;i++) cout<<mp[i]<<' ';
		if(c<=2) 
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++) 
				{
					s=0;
					p=i; q=j;
					dfs(0,i,j);
					//cout<<i<<"->"<<j<<' '<<minn[p][q]<<'\n';
					dfs2(0,i,j);
					if(s==2) 
					{
						//cout<<i<<' '<<j<<'\n';
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		else if(c==11||c==12) 
		{
			long long t=d/(a[2]-a[1]),ans=n,k=1,s=0;
			while(1)
			{
				s+=max(int(a[k]-a[k-1]),0);
				if(s<=d) 
				{
					k++;
					ans--;
				}
				else break;
			}
			for(;k<=n;k++) 
			{
				if(k%d==0) ans--;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
