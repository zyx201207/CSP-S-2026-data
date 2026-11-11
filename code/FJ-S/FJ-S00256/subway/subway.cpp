#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500005];
struct node{
	int k,a[500005],t[500005];
}b[505];
unordered_map<int,vector<pair<int,int>>> e;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].k;
		for(int j=1;j<=b[i].k;j++){
			cin>>b[i].a[j]>>b[i].t[j];
			e[b[i].a[j]].push_back({i,b[i].t[i]});
		}
	}
	while(q--){
		cin>>x>>y;
		long long ans=w[x]+w[y];
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				if(e[x][i].first==e[y][j].first){
					if(ans==w[x]+w[y]){
						ans+=e[x][i].second+e[y][j].second;
					}
					else{
						ans=min(ans,(long long)w[x]+w[y]+e[x][i].second+e[y][j].second);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

