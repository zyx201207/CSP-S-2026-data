#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000005;
ll c;
ll ans;
ll t, n, d;
ll cnt[5005][5005];
ll dis[5005];
ll sum = 1e18;
ll a[N];
struct node{
    ll now;
    ll val;
    bool operator < (const node &begin) const{
	    return val > begin.val;
	}
};
vector<ll>g[N];
priority_queue<node> q;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	ans = 0;
	    for (int i=0;i<n;i++){
		    for (int j=0;j<g[i].size();j++){
			    g[i][j] = 0;
			}
		}
		for (int i=1;i<=n;i++){
		    cin>>a[i];
		}
		for (int i=1;i<=n;i++){
		    for (int j=i;j<=n;j++){
		    	if(a[j] - a[i]<=d){
				    g[i].push_back(a[j] - a[i]);
				}
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
			    for (int k=1;k<=n;k++){
			        cnt[j][k] = 0;
			    }
			}
			for (int j=1;j<=n;j++){
			    dis[j] = sum;
			}
		    node ss;
		    ss.now = i;
		    ss.val = 0;
		    q.push(ss);
		    dis[i] = 0;
		    while(!q.empty()){
			    node orz = q.top();
			    q.pop();
			    ll now = orz.now;
			    ll val = orz.val;
			    for (int j=0;j<g[now].size();j++){
				    ll v = g[now][j];
				    if(dis[v]>dis[now]+1){
					    dis[v] = dis[now]+1;
					    cnt[i][v] = cnt[i][now]+1;
					}
				    if(dis[v]==dis[now]+1){
					    cnt[i][v]++;
				    }
				}
			}
			for (int j=1;j<=n;j++){
			    for (int k=1;k<=n;k++){
				    if(cnt[j][k] == 2){
					    ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;   
} 
