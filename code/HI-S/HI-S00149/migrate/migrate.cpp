#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e3 + 5;

ll x[N];
int mi[N];

ll sum[N];
ll dp[N][N];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,t;
	cin >> c >> t;
	
	queue<int> q;
	
	while(t--){
		
		memset(sum,0,sizeof sum);
		memset(mi,0,sizeof mi);
		memset(dp,0,sizeof dp);
		
		ll n,d;
		cin >> n >> d;
		
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		
		ll ans = 0;
		for(int l = 1; l < n; l++){
			
			for(int i = 1; i <= n; i++){
				mi[i] = 0;
				sum[i] = 0;
			}
			
			int last = l;
			
			mi[l] = 1;
			for(int i = l+1; i <= n; i++){

				if(x[i] - x[last] > d){
					
					if(last == i-1){
						mi[i] = -1;
						break; 
					}
					
					mi[i] = mi[i-1] + 1;
					last = i-1;
				} else{
					mi[i] = mi[i-1];
				}
				//cout << i << ' ' << mi[i] << '\n';
			}
			mi[l] = 0;
			
			while(!q.empty()) q.pop();
			
			for(int i = l; i <= n; i++){
				if(mi[i] == -1) break;
				
				while(!q.empty() && x[i] - x[q.front()] > d){
					sum[mi[q.front()]] -= dp[q.front()][mi[q.front()]];
					q.pop();
				}
				q.push(i);
				
				if(i == l){
					dp[l][0] = 1;
					sum[0] = 1;
				} else{
					dp[i][mi[i]] = sum[mi[i]-1];
					sum[mi[i]] += dp[i][mi[i]];
				}
				
				if(dp[i][mi[i]] == 2){
					ans++;
				}
			}
			
			/*cout << "-------" << '\n';
			for(int i = l; i <= n; i++){
				cout << i << ' ';
				for(int j = 0; j <= mi[i]; j++){
					cout << dp[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << "-------" << '\n';*/
			
		}
		cout << ans << '\n';
	}
	
	return 0;
}
