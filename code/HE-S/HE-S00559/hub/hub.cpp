#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+1;
const int INF=1e9+1;
int n,k;
vector<int> t[maxn];
int dist(int i,int j,int dis=0,int f=0){
	if(i==j){
		return dis;
	}
	int mn=INF;
	for(int v:t[i]){
		if(v==f) continue;
		mn=min(mn,dist(v,j,dis+1,i));
	}
	return mn;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		t[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u); 
	}
	int total=(1<<n);
	int mn=INF;
	for(int task=0;task<=total;task++){
		vector<int> s;
		for(int i=0;i<n;i++){
			if((task>>i)&1){
				s.push_back(i);
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			int mn2=INF;
			for(int j:s){
				mn2=min(mn2,dist(i,j));
			}
			mx=max(mx,mn2);
		} 
		mn=min(mn,mx);
	}
	cout<<mn<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	} 
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

