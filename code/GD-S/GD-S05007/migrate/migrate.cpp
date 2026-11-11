#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll MAXN = 1e3+5;
const ll INF = 1e18;

ll c, t, n, d, x[MAXN], f[MAXN][MAXN], res = 0; // 方案数 
ll dis[MAXN][MAXN]; // 最小步骤 

int main(){
//	freopen("migrate3.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;res = 0;
		for(ll i = 1; i <= n; i++){
			for(ll j = 1;j <= n; j++){
				f[i][j] = 0;
				dis[i][j] = INF;
			}
		}
		for(ll i =1; i <= n; i++){
			cin >> x[i];
//			while(!q.empty() && x[i]-x[q.front()] > d){
//				f[q.front()] = q.size()-1;
//				q.pop_front();
//			} 
//			q.push_back(i);
		}
		for(ll i = 1;i <= n; i++){
			ll lst = -1, minn, mincnt, minn2; // 属于x[i]-d的范围之内 
			for(ll j = i-1; j >= 1; j--){
				if(x[i]-x[j] <= d){
					f[j][i] = 1;
					dis[j][i] = 1;
					lst = j;
				}else if(lst != -1){
					minn = INF, mincnt = 0; // 最小值与最小值的计数 
					for(ll p = lst; p <= i-1; p++){
						if(minn > dis[j][p]){
							minn = dis[j][p];
							minn2 = f[j][p];
							mincnt = 1;
						}else if(minn == dis[j][p])mincnt++; 
					}
					f[j][i]=minn2*mincnt;
					dis[j][i] = minn+1; 
//					f[j][i] = f[j][lst-1];
				}else break;
				if(f[j][i] == 2) res++;
//				cout << j<<"->" << i << ": " << f[j][i] << " " << mincnt << " " << minn << endl; 
//				cout << dis[j][i] << endl;
			}
		}
		cout << res << endl; 
		
//		while(!q.empty()){
//			f[q.front()] = q.size()-1;
//			q.pop_front();
//		}
//		for(ll i = 1; i <= n; i++){
//			cout << f[i] << " ";
//		}cout << endl;
		
	}
	return 0;
} 
