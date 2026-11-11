#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e2+10, M = 2e6+10;
int a[N],a1[M];
int c,n,d;
int dis[N][N];
int cnt[N][N];

void Input1(){
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a1[i];
	}
}

void Solve1(){
	if(d <= a1[2]-a1[1]){
		cout << 0 << '\n';
		return;
	}
	int tmp = d/(a1[2]-a1[1]);
	tmp = tmp+tmp-1;
	cout << max(n-tmp, 0LL) << '\n';
}

void Input(){
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
}

void Solve(){
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	//build graph
	for(int i=1;i<=n;i++){
		dis[i][i] = 0;
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j]) <= d){
				dis[i][j] = 1;
				dis[j][i] = 1;
				cnt[i][j] = 1;
				cnt[j][i] = 1;
			}
		}
	}
	//work out the shortest path,Floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k] + dis[k][j] == dis[i][j]){
					cnt[i][j] += cnt[i][k]*cnt[k][j];
				}else if(dis[i][k] + dis[k][j] < dis[i][j]){
					cnt[i][j] = cnt[i][k]*cnt[k][j];
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//cout << cnt[i][j] << ' '; 
			if(cnt[i][j] == 2) ans++;
		}
	}
	cout << ans << '\n';
}

signed main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	cin >> c >> T;
	if(c == 11 || c == 12){
		while(T--){
			Input1();
			Solve1();
		}
	}else{
		while(T--){
			Input();
			Solve();
		}
	}
	
	return 0;
}
