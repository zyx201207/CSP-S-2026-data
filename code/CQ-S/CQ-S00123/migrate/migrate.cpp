#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10, M=5010;
int c, t, n, d;
int x[N];
int dis[M], cnt[M];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >>c >>t;
	if(11 <= c && c <= 12){
		while(t--){
			cin >>n >>d;
			if(n <= 1){
				for(int i=1; i<=n; i++){
					int tmp;
					cin >>tmp;
				}
				cout <<0 <<endl;
			}else{
				int a1, a2;
				cin >>a1 >>a2;
				for(int i=3; i<=n; i++){
					int tmp;
					cin >>tmp;
				}
				int m = abs(a2 - a1);
				if(d / m <= 1) cout <<0 <<endl;
				else cout <<max(n - (d / m * 2 - 1), 0ll) <<'\n';
			}
		}
		return 0;
	}else if(13 <= c && c <= 14){
		while(t--){
			int ans = 0;
			cin >>n >>d;
			for(int i=1; i<=n; i++)
				cin >>x[i];
			for(int i=n, j=n, k=n; i>=1; i--){
				while(x[i] + d < x[j]) j --;
				while(x[j] + d < x[k]) k --;
				ans += k - j;
			}
			cout <<ans <<'\n';
		}
	} 
	while(t--){
		cin >>n >>d;
		for(int i=1; i<=n; i++)
			cin >>x[i];
		int ans = 0;
		for(int i=1; i<=n; i++){
			memset(dis, 0x7f, sizeof dis);
			memset(cnt, 0, sizeof cnt);
			dis[i] = 0, cnt[i] = 1;
			for(int j=i+1, a=i, val=cnt[i]; j<=n; j++){
				if(x[j-1] + d < x[j]) break;
				while(x[a] + d < x[j]){
					val -= cnt[a], a ++;
					if(val == 0)
						for(int k=a; dis[k] == dis[a]; k++)
							val += cnt[k];
				}
				dis[j] = dis[a] + 1;
				cnt[j] = val;
				ans += cnt[j] == 2;
			}
		}
		cout <<ans <<'\n';
	}
	return 0;
}

