#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt;
long long v[305],ans,k;
void dfs(int x,int r,long long sum,long long step)
{
	if(x==r && step==r-1)
	{
		if(ans==-1)
		{
			ans=sum;
			cnt=1;
		}
		else if(ans==sum)	cnt++;
		else if(sum<ans)
		{
			cnt=1;
			ans=sum;
		}
		return ;
	}
	else
	{
		for(int i=x+1;i<=r && v[x]+d>=v[i];i++)
			dfs(i,r,sum+v[i]-v[x],step+1);		
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		k=0;
		memset(v,0,sizeof v);
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>v[i];
		if(n<3)	cout<<"0\n";
		else
		{
			for(int i=1;i<n-1;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					cnt=0;
					ans=-1;
					dfs(i,j,0,0);
					if(cnt==2)	k++;
				}
			}			
		} 
		cout<<k<<"\n";
	}
	return 0;	
} 
