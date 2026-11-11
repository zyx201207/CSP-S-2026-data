#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N = 2e6 + 9;
const ll inf = 2e15;
const ll NEG = -2e15;
const ll mod = 1e9 + 7;
ll x[N];
void solve(){
	int n;ll d;
	scanf("%d %lld",&n,&d);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&x[i]);
	}
	
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i + 3;j <= n;j++){
			priority_queue<pli,vector<pli>,greater<pli> >q;
			q.push({0,i});
			ll mn = inf;
			int cnt = 0;
			while(!q.empty()){
				pli g = q.top();
				q.pop();
//				cout << g.second << ' ' << g.first << '\n';
				if(g.second == j){
					if(g.first == mn){
						cnt++;
					}
					else if(mn == inf){
						mn = g.first;
						cnt++;
					}
					else break;
				}
				for(int k = g.second + 1;k <= j;k++){
					if(x[k] - x[g.second] <= d){
						q.push({g.first+1,k});
					}
					else break;
				}
			}
//			cout << cnt << ' ';
			if(cnt == 2){
//				cout << i << ' ' << j << ' ' << mn << '\n'; 
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}
