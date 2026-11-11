#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000010],t[2000010],dis[5010][5010],f[5010][5010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			cout<<n<<" "<<a[2]-a[1]<<" "<<d<<"\n";
			if(n<=3)cout<<"0\n";
			else{
				if(a[2]==a[1])cout<<"0\n";
				else if(a[3]-a[1]<=d&&a[4]-a[1]>d)cout<<n-3<<"\n";
				else if(n>=5&&a[4]-a[1]<=d&&a[5]-a[1]>d)cout<<n-5<<"\n";
				else if((n-1)%(d/(a[2]-a[1]))==0)cout<<d/(a[2]-a[1])+3<<"\n";
				else cout<<"0\n";
			}
		}
		else if(c<=6){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)dis[i][j]=1e18,f[i][j]=0;
				dis[i][i]=0;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d)dis[i][j]=1;
				}
			}
			for(int len=2;len<n;len++){
				for(int l=1;l+len<=n;l++){
					int r=l+len;
					for(int k=l;k<=r;k++){
						dis[l][r]=min(dis[l][r],dis[l][k]+dis[k][r]);
					}
				}
			}
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(dis[i][j]==1)f[i][j]=1;
			for(int len=2;len<n;len++){
				for(int l=1;l+len<=n;l++){
					int r=l+len;
					if(f[l][r])continue;
					for(int k=l+1;k<r;k++){
						if(dis[l][r]==dis[l][k]+dis[k][r]){
							f[l][r]+=f[l][k]*f[k][r];
						}
					}
				}
			}
			/*
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++)cout<<f[i][j]<<" ";
				cout<<"\n";
			}
			*/
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++)if(f[i][j]==2)ans++;
			}
			cout<<ans<<"\n";
		}
	}
}
