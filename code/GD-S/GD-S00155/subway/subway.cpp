#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v,w;
};
vector<Node> a[1500005];
int c,m,n,d,q,k,ans;
int aa[500005],bb[500005];
int dis[1500005],f[1500005];
bool v[1500005];
void Dijkstra(){
	memset(dis,10623,sizeof dis);
	memset(v,false,sizeof v);
	dis[1]=0;
	f[1]=1;
	for (int i=1;i<=m*3;i++){
		int u=-1;
		for (int j=1;j<=m*3;j++){
			if (!v[j] && (u==-1 || dis[u]>dis[j])){
				u=j;
			}
		}
		if (u==-1){
			break;
		}
		v[u]=1;
		for (auto [v,w]:a[u]){
			cout<<u<<" "<<v<<" "<<w<<"\n";
			cout<<dis[u]<<" "<<dis[v]<<"\n";
			if (dis[v]>dis[u]+w){
				//cout<<dis[v]<<" "<<dis[u]<<" "<<w<<"\n";
				dis[v]=dis[u]+w;
				f[v]=u;
			}
		}
	}
}
/*
void found(int aaa,int bbb){
	if (f[bbb*3]==aaa*3-2){
		ans
	}
}
*/
//i*3-2 = kou  i*3-1 = ting  i*3=tai
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		int aaa;
		cin>>aaa;
		a[i*3-1].push_back({i*3-2,aaa});
		a[i*3-2].push_back({i*3-1,aaa});
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>aa[j]>>bb[j];
			a[aa[j]*3].push_back({aa[j]*3-1,bb[j]});
			a[aa[j]*3-1].push_back({aa[j]*3,bb[j]});
			if (j>1){
				a[aa[j]*3].push_back({aa[j-1]*3,0});
				a[aa[j-1]*3].push_back({aa[j]*3,0});
			}
		}
	}
	Dijkstra();
	/*
	for (int i=1;i<=m*3;i++){
		cout<<dis[i]<<" ";
	}
	*/
	while (q--){
		ans=0;
		int aaa,bbb;
		cin>>aaa>>bbb;
		ans=dis[bbb*3-2]-dis[aaa*3-2];
		//found(aaa,bbb);
		cout<<ans<<"\n";
	}
	return 0;
	/**/
}
