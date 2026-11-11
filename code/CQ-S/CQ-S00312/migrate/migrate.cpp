#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long C,T,a[N];
long long dist[5000][5000];
long long cnt[5000][5000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--){
		memset(dist,-1,sizeof dist);
		memset(cnt,0,sizeof cnt);
		memset(a,0,sizeof a); 
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			dist[i][i]=0;
		}
		for(long long lenth=2;lenth<=n;lenth++){
			for(long long i=1;i+lenth-1<=n;i++){
				long long j=i+lenth-1;
				for(long long k=j-1;k>=i;k--){
					if(a[j]-a[k]<=d&&dist[i][k]!=-1){
						if(dist[i][j]==-1){
							dist[i][j]=dist[i][k]+1;
							cnt[i][j]=1;
						}else if(dist[i][j]==dist[i][k]+1){
							cnt[i][j]++;
						}else if(dist[i][j]>dist[i][k]+1){
							cnt[i][j]=1;
							dist[i][j]=dist[i][k]+1;
						}
					}
					if(a[j]-a[k]>=d){
						break;
					}
				}
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
