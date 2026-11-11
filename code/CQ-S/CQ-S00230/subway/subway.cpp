#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll wysj,n,m,q,sr1,sr2,ans,cz[500005],g[505][505];
struct node{
	ll to,w;
};
vector<node> ha[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>wysj>>n>>m>>wysj>>q;
	for(ll i=1;i<=m;i++) cin>>cz[i];
	memset(g,0x3f,sizeof(g));
	for(ll i=1;i<=n;i++){
		cin>>wysj,g[i][i]=0;
		while(wysj--){
			cin>>sr1>>sr2;
			ha[sr1].push_back({i,sr2});
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<(ll)ha[i].size();j++){
			for(ll k=j+1;k<(ll)ha[i].size();k++){
				g[ha[i][j].to][ha[i][k].to]=min(g[ha[i][j].to][ha[i][k].to],ha[i][j].w+ha[i][k].w);
				g[ha[i][k].to][ha[i][j].to]=min(g[ha[i][k].to][ha[i][j].to],ha[i][j].w+ha[i][k].w);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		cin>>sr1>>sr2,ans=0x3f3f3f3f3f3f3f3f;
		for(ll i=0;i<(ll)ha[sr1].size();i++){
			for(ll j=0;j<(ll)ha[sr2].size();j++){
				ans=min(ans,cz[sr1]+ha[sr1][i].w+ha[sr2][j].w+cz[sr2]+g[ha[sr1][i].to][ha[sr2][j].to]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
