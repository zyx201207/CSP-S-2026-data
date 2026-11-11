#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
using namespace std;
int t, n;
ll d, a[100005], ans;
ll minndis = 999999999, cnt;
bool flag = 1;
void dfs(int x, int limit, int dep){
	//cout << x << " " << limit << endl;
	if(x >= limit){
		if(minndis == 999999999){
			minndis = dep;
			cnt++;
		}else if(minndis == dep){
			cnt++;
		}else if(minndis < dep){
			if(cnt != 2){
				flag = 0;
			}
		}if(cnt >= 3){
			flag = 0;
		}return;
	}
	int k = x + 1;
	while(a[k] - a[x] <= d){
		dfs(k, limit, dep + 1);
		k++;
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		rep(i, 1, n)cin >> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 2; j <= n; j++){
				minndis = -1, cnt = 0;
				flag = 1;
				dfs(i, j, 0);
				ans += flag;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
