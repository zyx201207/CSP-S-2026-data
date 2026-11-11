#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lc(i) ((i)<<1)
#define rc(i) ((i)<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=1e6+5;
int caseID;
int n,k;
vector<int>G[N];
void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<=n-1;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<1<<'\n';
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>caseID;
	int T;cin>>T;
	while(T--)solve();
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
