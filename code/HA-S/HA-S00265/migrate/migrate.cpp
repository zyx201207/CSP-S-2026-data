#include<bits/stdc++.h>
using namespace std;
const long long _MAX = 1e5+5;
#define ll long long
#define ull unsigned long long

ll c , T , n , d , ans , x[_MAX] , dis[_MAX] , cnt[_MAX];
bool flag[_MAX] , fflag[_MAX];
vector<ll> e[_MAX];
queue <ll> qe;

void dj(ll x){
	memset(dis,0x7f,sizeof(dis));memset(flag,0,sizeof(flag));memset(fflag,0,sizeof(fflag));
	dis[x] = 0;
	qe.push(x);
	while(qe.size()){
		ll u = qe.front();
		qe.pop();
		fflag[u] = 0;
		for (int i = 0 ; i < e[u].size() ; i ++){
			ll v = e[u][i];
			if (dis[v] > dis[u] + 1){
				//cout << v << endl;
				cnt[v] = 1;
				dis[v] = dis[u] + 1;
				if (!fflag[v]){
					qe.push(v);
					fflag[v] = 1;
				}
			}
			else if(dis[v] == dis[u] + 1) cnt[v] ++;
			//cout << u << ' ' << v << ' ' << dis[u] << ' ' << dis[v] << ' ' << cnt[v] << endl;
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while(T--){
		ans = 0;
		for (int i = 0 ; i < _MAX ; i ++) e[i].clear();
		cin >> n >> d;
		for (int i = 1 ; i <= n ; i ++){
			cin >> x[i];
		}
		ll l = 1 , r = 1;
		for (;r <= n ; r ++){
			while(x[r]-x[l] > d) l++;
			if (l == r) continue;
			//cout << "make " << l << ' ' << r << endl;
			e[l].push_back(r);
			e[r].push_back(l);
		}
		for (int i = 1 ; i <= n ; i ++){
			dj(i);
			for (int j = i + 1 ; j <= n ; j++){
				//cout << cnt[j] << ' ';
				if (cnt[j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

