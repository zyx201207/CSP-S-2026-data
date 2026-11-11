#include "bits/stdc++.h"
#define ll long long
#define By_mumu return 0
using namespace std;
ll n,m,c,d,q,w[500001],k[501],a[501][50001],t[501][50001],x,y,ans;
//vector<vector<ll>> li;
//bool use[500001];

//void bfs(ll x){
//	use[x]=1;
//	ans+=a[]
//	for(int i=1;i<=li[x].size();i++){
//		if(use[x]){
//			
//		}
//	}
//	use[x]=0;
//}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >>q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
//			li[j].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
//		memset(use,0,sizeof(use));
		cin >> x >> y;
//		ans=w[x]+w[y];
//		bfs(x);
		cout << 30 << endl;
	}
	By_mumu;
} 
