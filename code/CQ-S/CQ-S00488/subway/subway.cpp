#include<bits/stdc++.h>
using namespace std;
using t64 = long long;
constexpr t64 INF = 1000000000000000000;
struct side{
	t64 v,w;
};
vector<side> mp[500005];
t64 w[500005];
t64 a[500005];
t64 t[500005];
t64 c,n,m,d,q;
t64 dis[500005];
t64 vis[500005];
void spfa(t64 s){
	for(t64 i=1;i<=500004;i++){
		dis[i] = INF;
		vis[i] = 0;
	}
	queue<t64> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()){
		t64 u=q.front();
		q.pop();
		vis[u]=0;
		for(side nw:mp[u]){
			t64 v = nw.v;
			t64 w = nw.w;
			if((__int128)dis[v]>(__int128)dis[u]+w){
				dis[v] = dis[u]+w;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main(){
//	cout<<2*INF<<endl;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(t64 i=1;i<=m;i++)
		cin >> w[i];
	for(t64 i=1;i<=n;i++){
		t64 ki;
		cin >> ki;
		for(t64 j=1;j<=ki;j++)
			cin >> a[j] >> t[j];
		for(t64 j=1;j<ki;j++){
			for(t64 k=j+1;k<=ki;k++){
//				cout << j <<' '<<k<<endl;
				mp[a[j]].push_back({a[k],t[j]+t[k]});
				mp[a[k]].push_back({a[j],t[j]+t[k]});
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		cout << i <<":\n";
//		for(auto nw:mp[i]){
//			cout << "v" << nw.v<<"w"<<nw.w<<endl;
//		}
//	}
	while(q--){
		t64 a,b;
		cin >> a>>b;
		spfa(a);
		cout << w[a]+dis[b]+w[b]<<'\n';
	}
	return 0;
} 
