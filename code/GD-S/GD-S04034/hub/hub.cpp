#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pii>
#define fi first
#define se second
int n,m;
vi g[1000010];
void work(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int kk=n>>1;
	if(m>kk){
		if(m==n)cout<<"0\n";
		else cout<<"1\n";
		return;
	}
	cout<<((kk+1-m)>>2)+1<<"\n";
//	for(int i=0;i<=k;i++){
//		
//	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cid;
	cin>>cid;
	int t=1;
	cin>>t;
	while(t--){
		work();	
	}
}
/*
0 1
5 3
-2 -1 0 1 2

0 1
5 2
-2 -1 0 1 2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
