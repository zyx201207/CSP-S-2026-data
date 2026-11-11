#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, dis[5002][5002], cnt[5002][5002], x[5002], ans;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		memset(dis, 0x3f, sizeof(dis));
		memset(cnt, 0, sizeof(cnt));
		cin>>n>>d;
		for(int i = 1; i <= n; i++){
			dis[i][i]=0, cnt[i][i]=1;
			cin>>x[i];
			int j = i;
			while(x[i]-x[--j]<=d&&j>0){
				for(int k = 1; k <= j; k++){
					if(dis[k][j]+1<dis[k][i]){
						dis[k][i]=dis[k][j]+1;
						cnt[k][i]=0;
					}
					if(dis[k][j]+1==dis[k][i]){
						cnt[k][i]+=cnt[k][j];
					}
				}
			}
		}
		ans=0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}