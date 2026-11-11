#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int key[510][MAXN],t[510][MAXN];
int w[510];
vector<int>g[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//站口走到站厅时间 
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>key[i][j]>>t[i][j];
			g[i].push_back(j);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=x+1;i<y;i++){
			ans+=t[1][1];
			ans+=t[1][1];
		}
		ans+=w[x];
		ans+=w[y];
		ans+=t[1][1];
		ans+=t[1][1];
		cout<<ans;
		if(q>1) cout<<"\n";
	}
	return 0;
}
