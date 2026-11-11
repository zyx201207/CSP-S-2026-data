#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],kskbl[500005],abc[500005]={0x3f3f3f3f};
int G[505][505],zdjd[505][505];
vector<pair<int,int>> ng[505];
vector<int> wkzkbl[500005];
void solve1(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(G[i][k]+G[k][j]<G[i][j]){
					G[i][j]=G[i][k]+G[k][j];
				}
			}
		}
	}
}
void newG(){
	for(int i=1;i<=m;i++){
		if(wkzkbl[i].size()>1){
			for(int j=0;j<(int)wkzkbl[i].size();j++){
				for(int k=0;k<(int)wkzkbl[i].size();k++){
					if(j!=k) {
						int dis=0x3f3f3f3f;
						for(int z=0;z<(int)ng[j].size();z++) {
							if(ng[j][z].first==i) {
								dis=ng[j][z].second;
								break;
							}
						}
						for(int z=0;z<(int)ng[k].size();z++){
							 if(ng[k][z].first==i) {
								 dis+=ng[k][z].second;
								 break;
							 }
						 }
						 G[j][k]=dis;
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			ng[k].push_back({a,t});
			wkzkbl[j].push_back(k);
			abc[i]=min(abc[i],t);
		}
	}
	newG();
	solve1();
	for(int i=0;i<q;i++){
		int x,y;
		int ans=0;
		cin>>x>>y;
		ans+=G[x][y];
		ans+=w[x]+w[y];
		ans+=abc[x]+abc[y];
	}
	return 0;
}
//我写了半个多小时发现题目没有看明白，导致我写的全是错的，我真服了，而且我还不知道这一题目怎么写
//好像写错了，来不及改了，不管了，我常常追忆过去
