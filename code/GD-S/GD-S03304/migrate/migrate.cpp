#include<bits/stdc++.h>
using namespace std;
typedef long long llong;
const int maxn=505,inf=0x3fffffff;
int n,dist[maxn][maxn],cnt[maxn][maxn];
llong d,x[maxn];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		fill(dist[i]+1,dist[i]+n+1,inf);
		dist[i][i]=0;
	}
	for(int i=1;i<=n;++i){
		fill(cnt[i]+1,cnt[i]+n+1,1);
	}
	for(int i=1;i<=n;++i){
		cin>>x[i];
		for(int j=1;j<i;++j){
			if(x[i]-x[j]<=d){
				dist[i][j]=dist[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int k=1;k<=n;++k){
			for(int j=1;j<=n;++j){
				if(i==k||j==k||i==j){
					continue;
				}
				int d=dist[i][k]+dist[k][j];
				if(dist[i][j]>d){
					dist[i][j]=d;
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}else if(dist[i][j]==d){
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
	}
	llong ans=0;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			if(cnt[i][j]==2){
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
