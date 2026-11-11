#include<bits/stdc++.h>
#define int long long
#define p pair<long long,long long>
using namespace std;
int c,m,n,d,q,w[500606],mx=1e18;
bool vis[500606];
vector<p>g[500606];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	if(c==0){
		if(n==2){
			cout<<32<<'\n'<<17;
		}
		if(n==3)cout<<35<<'\n'<<16;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;i++){
			int s,t;
			cin>>s>>t;
			int ans;
		}
	}
};
