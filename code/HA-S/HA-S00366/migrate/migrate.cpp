#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll x;cin>>x;return x;}
const int N=310;
ll n,d,ans,dis[N][N],a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);
	for(int c=read(),T=read();T;T--){
		n=read(),d=read();
		ans=0;
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=1e18;
		for(int i=1;i<=n;i++){
			int pos=upper_bound(a+i+1,a+n+1,a[i]+d)-a-1;
			for(int j=i+1;j<=pos;j++)
				dis[i][j]=1;
		}
		for(int len=3;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1,cnt=0;
				for(int k=i+1;k<j;k++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				if(dis[i][j]==1e18) continue;
				for(int k=i+1;k<j;k++)
					if(dis[i][j]==dis[i][k]+dis[k][j]) cnt++;
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
