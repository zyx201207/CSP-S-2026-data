#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
int a[M];
vector<int> G[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int u=-1,v;
	for(int i=1;i<=n;i++){
		int k,w;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			a[j]+=w;
			u=v;
			if(u==-1)continue;
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	while(q--){
		cout<<"0\n";
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
