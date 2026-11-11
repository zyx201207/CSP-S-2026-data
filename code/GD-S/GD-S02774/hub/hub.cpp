#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6 + 10;
int c,t;
int n,k,u,v;
vector<int> g[N]
bool vis[N];
 void pd(){
 	int sum1 = 0;
 	int sum2 = 0;
 	for(int i = 0;i<n;i++){
 		if(vis[i]){
 			sum2++;
		 }
		 if(sum2 > k){
		 	
		 }
	 }
 }
void sol(int st){
	vis[st] = 1;
//	for(int int i = g[u];i<n;i++){

	for(auto v:g[st]){
		if(!vis[v]){
			sol(st);
		}
	}
	retunrn;
}
void sol2(int u,int x){
	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		for(int i = 0;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<n / 2<<' ';
	}
	return 0;
}

