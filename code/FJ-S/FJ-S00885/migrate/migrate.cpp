#include<bits/stdc++.h>
using namespace std;
long long t1,ans;
bool r[2000003];
long long c,t,m,n,d;
long long x[2000003];
long long w[2000003],ans1;
vector <long long> a[2000003];
long long dp[2000003],sh[2000003];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ch=1;ch<=t;ch++)
	{
		ans=0;
		cin>>n>>d;
		for(long long j=1;j<=n;j++)
		{
			cin>>x[j];
			a[j].clear();
		}
		for(long long j=1;j<=n;j++)
		{
			for(long long i=j+1;i<=n;i++)
			{
				if(x[i]-x[j]<=d)
				{
					w[j]++;
					a[i].push_back(j);
				}
			}
		}
		//算可以一次往后飞多少个岛屿，并记录边 
		for(int i=1;i<=n;i++)
		{
			memset(dp,0,sizeof(dp));
			memset(sh,0x3f,sizeof(sh));
			for(long long j=i+1;j<=n;j++)
			{
				//cout<<i<<" "<<j<<endl;
				if(d>=(j-i))
				{
					sh[j]=1;
					dp[j]=1;
					continue;
				}
				sh[j]=INT_MAX;
				for(long long k : a[j])
				{
					t1=sh[k]+1;
					if(sh[j]==t1)
					{
						ans1+=dp[k];
						//cout<<111<<" i"<<i<<" k"<<k<<" j"<<j<<endl;
					}
					//cout<<"t1"<<" "<<t1<<endl; 
					//cout<<sh[i][j]<<endl;
					//cout<<(sh[i][j]>t1)<<endl;
					if(sh[j]>t1)
					{
						ans1=1;
						//cout<<112<<" i"<<i<<" k"<<k<<" j"<<j<<endl;
						sh[j]=t1;
						//cout<<123<<endl;
					}
				}
				dp[j]=ans1;
				//if(i==1 && j==4) cout<<14<<" "<<ans1<<endl;
				//if(i==2 && j==5) cout<<25<<" "<<ans1<<endl;
				if(sh[j]==INT_MAX) continue;
				if(dp[j]==2)
				{
					//cout<<i<<" "<<j<<" sh[i][j]"<<sh[i][j]<<endl;
					//cout<<"       "<<ans<<endl;
					ans++;
					//cout<<111111111111111<<" "<<i<<j<<" "<<ans<<endl;
				}
				//cout<<i<<" "<<j<<" sh[i][j]"<<sh[i][j]<<endl;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
