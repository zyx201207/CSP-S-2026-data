#include <bits/stdc++.h>
using namespace std;

struct road{ 
	int u;
	int v;
	int m;
}q[5000002];

int s, u, c, t, n, l, r, rr, ans, vis[5002][5002], cnt[5002][5002];
long long d, p[5002];
int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		for(int i = 0; i < 5000; ++i){
			for(int j = i+1; j < 5000; ++j){
				cnt[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		l = 0;
		r = -1;
		ans = 0;
		
		cin>>n>>d;
		for(int i = 0; i < n; ++i){	
			cin>>p[i];
			while(l < r && p[i] - p[q[l].v] > d){
				++l;
			}
			
			s = r - l + 1;
			for(int j = l; j < l + s; ++j){
				u = q[j].u;

				if(vis[u][i] == -1){
					vis[u][i] = q[j].m;
				}
				
				if(vis[u][i] == q[j].m){
				
					if(++cnt[u][i] == 2){
						++ans;
					}else if(cnt[u][i] == 3){
						--ans;
					}
				}
			
				q[j + s].u = u;
				q[j + s].v = i;
				q[j + s].m = q[j].m+1;
			}
			r = l + s + s;
			q[r].u = i;
			q[r].v = i;
			q[r].m = 0;
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}
