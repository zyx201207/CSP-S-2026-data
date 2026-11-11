#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
const int INF=1e18;
int c,T,n,d,a[N],ans;
int dis[N][N],cnt[N][N];
//deque<int> q;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=INF;
			}else{
				dis[i][j]=0;
			}
			cnt[i][j]=0;
		}
	}
	for(int i=1,j=1;i<=n;i++){
		while(a[i]-a[j]>d){
			j++;
		}
		for(int k=j;k<i;k++){
			dis[k][i]=1;
			cnt[k][i]=1;
		}
		for(int k=1;k<j;k++){
			for(int l=j;l<i;l++){
				if(dis[k][l]+1<dis[k][i]){
					dis[k][i]=dis[k][l]+1;
					cnt[k][i]=cnt[k][l];
				}else if(dis[k][l]+1==dis[k][i]){
					cnt[k][i]+=cnt[k][l];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
