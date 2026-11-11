#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
long long n,m,d,q,ans;
vector<pii> ln[505],e[505];int w[500005];bool vis[500005][505];
int f[505];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int t,a;
			cin>>a>>t;
			ln[i].push_back(make_pair(a,t));
			vis[a][j]=1;
		}
	}
	return 0;
}
