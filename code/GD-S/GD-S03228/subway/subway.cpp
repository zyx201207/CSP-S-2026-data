#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505,M = 5e5 + 5;
ll c,n,m,d,q,mp[1003][1003],w[M],a[M],t[M],T;
vector <ll> emt[M];
deque <pair<ll, ll>> dq;
bool vis[M];

int emt_bless_me(int rp){return rp++;}

int main(){
	cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	for(int i = 0;i <= 1002;i++)mp[i][i] = 0;
	cin>>c>>n>>m>>d>>q;
	if(c <= 11){
		for(int i = 1;i <= m;i++)cin>>w[i];
		for(int i = 1;i <= n;i++){
			int k = 0;
			cin>>k;
			memset(a,0,sizeof(a));
			memset(t,0,sizeof(t));
			for(int j = 1;j <= k;j++)cin>>a[j]>>t[j];
			ll sum = 0;
			for(int x = 1;x < k;x++)for(int y = x + 1;y <= k;y++){
				sum = t[x] + t[y];
				mp[a[x]][a[y]] = mp[a[y]][a[x]] = sum < mp[a[x]][a[y]] ? sum : mp[a[x]][a[y]];
			}
		}
		ll sum = 0;
		for(int i = 1;i < m;i++){
			for(int j = i + 1;j <= m;j++){
				for(int k = 1;k <= m;k++){
					if(i != k && j != k){
						sum = mp[i][k] + mp[k][j];
						mp[i][j] = mp[j][i] = sum < mp[i][j] ? sum : mp[i][j];
					}
				}
			}
		}
		/*for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++){
				cout<<mp[i][j]<<' ';
			}
			cout<<'\n';
		}*/
		ll x = 0,y = 0;
		for(int i = 1;i <= q;i++){
			cin>>x>>y;
			cout<<w[x] + w[y] + mp[x][y]<<'\n';
		}
	}
	else{
		//cout<<'!';
		for(int i = 1;i <= m;i++)cin>>w[i];
		//cout<<'!';
		for(int i = 1;i <= n;i++){
			int k = 0;
			cin>>k;
			memset(a,0,sizeof(a));
			memset(t,0,sizeof(t));
			//cout<<'!';
			for(int j = 1;j <= k;j++)cin>>a[j]>>t[j];
			for(int x = 1;x < k;x++)for(int y = x + 1;y <= k;y++)emt[a[x]].emplace_back(a[y]),emt[a[y]].emplace_back(a[x]);
		}
		//cout<<'!';
		T = t[1];
		ll x = 0,y = 0;
		for(int i = 1;i <= q;i++){
			dq.clear();
			memset(vis,0,sizeof(vis));
			cin>>x>>y;
			dq.push_back(make_pair(x,0));
			while(!dq.empty()){
				pair <ll, ll> now = dq.front();
				dq.pop_front();
				vis[now.first] = true;
				if(now.first == y){
					//cout<<now.second<<' ';
					cout<<w[x] + w[y] + now.second * T * 2<<'\n';
					break;
				}
				for(auto& i : emt[now.first]){
					if(!vis[i]){
						//cout<<i<<' ';
						dq.emplace_back(make_pair(i,now.second + 1));
						vis[i] = true;
					}
				}
				//cout<<'\n';
			}
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

19 2 5 20 2
4 1 9 2 5
3 1 1 2 1 4 1
3 2 1 3 1 5 1
1 3
1 2

32
17

*/
