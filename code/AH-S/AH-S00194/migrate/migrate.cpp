#include<bits/stdc++.h>
using namespace std;
const int N=5010;
#define int long long
int c,T,n,q,a[N];
int d[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		memset(d,0,sizeof d);
		int ans=0;
		map<pair<int,int>,int> mp;
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(i!=j&&abs(a[i]-a[j])<=q) d[j][i]=d[i][j]=abs(a[i]-a[j]);
			}
			if(i!=1&&i!=n&&abs(a[i]-a[i-1])>q&&abs(a[i]-a[i+1])>q) for(int j=1;j<=n;j++)
			{
				d[i][j]=-1;
				d[j][i]=-1;
				if(i==j) d[i][j]=0;
			}
			if(i==1&&abs(a[i]-a[i+1])>q) for(int j=1;j<=n;j++)
			{
				d[i][j]=-1;
				d[j][i]=-1;
				if(i==j) d[i][j]=0;
			}
			if(i==n&&abs(a[i]-a[i-1])>q) for(int j=1;j<=n;j++)
			{
				d[i][j]=-1;
				d[j][i]=-1;
				if(i==j) d[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(i!=j&&d[i][j]!=-1) d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(i<k&&k<j&&d[i][j]!=-1&&i!=j&&d[i][j]==d[i][k]+d[k][j])
					{
						mp[{min(i,j),max(i,j)}]++; 
					}
				}
			}
		}
		for(auto u:mp)
			if(u.second==2)
			{
				ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
