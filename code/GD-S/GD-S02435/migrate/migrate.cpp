#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E6+7;
int n,step;
int x[N],d[N],cnt[N];
void dfs(int u,int dis){
	if(dis<d[u]){
		cnt[u]=1;
		d[u]=dis;
	}
	else if(dis==d[u]) cnt[u]++;
	else return;
	for(int i=u+1;i<=n&&x[i]-x[u]<=step;i++){
		dfs(i,dis+1);
	}
	for(int i=u-1;i>=1&&x[u]-x[i]<=step;i--){
		dfs(i,dis+1);
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t >> t;
	while(t--){
		cin >> n >> step;
		for(int i=1;i<=n;i++) cin >> x[i];
		if(n>20){
			cout << "0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(d,0x3f,sizeof d);
			memset(cnt,0,sizeof cnt);
			d[i]=0;
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
