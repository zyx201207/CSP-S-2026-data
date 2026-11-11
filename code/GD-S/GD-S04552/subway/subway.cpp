#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+7,N=5e2+7;
struct ac{
	int t,to;
};
vector<ac> g[M];
int c,n,m,d,q;
int id;
int Tim[M];
vector<pair<int,int> > a[N];
int w[M];
int ans;
int inf[M];
map<int,int> vis;
vector<int> al[M];
int ANS;
int tak[M];
void dfs(int id,int u,int cost,int v){
//	cout<<id<<" "<<u<<" "<<cost<<" "<<v<<"\n";
	if(u==v){
		ans=min(ans,cost+tak[id]);
		return ;
	}
	for(ac i:g[id]){
		if(!vis[i.to]){
			vis[i.to]=1;
			dfs(i.to,inf[i.to],cost+i.t,v);
			vis[i.to]=0;
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int la=0,lt=0;
		int A,T; 
		for(int j=1;j<=k;j++){
			cin>>A>>T;
			id++;
			al[A].push_back(id);
			a[i].push_back({A,id});
			tak[id]=T;
			inf[id]=A;
			Tim[id]=T;
			if(la or lt){
				ac in;
				in.t=0,in.to=id;
				g[id-1].push_back(in);
//				cout<<id-1<<"to"<<id<<"\n";
				in.to=id-1;
				g[id].push_back(in);
			}
			la=A,lt=T;
		}
	}
	for(int i=1;i<=m;i++){
		int x=0;
		pair<int,int> y[n+5];
		for(int j:al[i]){
			y[++x]={Tim[j],j};
		}
//		for(int j=1;j<=n;j++){
//			for(pair<int,int> k:a[j]){
//				if(k.first==i){
//					y[++x]={Tim[k.second],k.second};//time,id
//				}
//			}
//		}//onm
//		cout<<i<<"::::";
//		for(int j=1;j<=x;j++){
//			cout<<y[j].first<<"_"<<y[j].second<<" ";
//			
//		}
//		cout<<"\n";
		for(int j=1;j<=x;j++){
			for(int k=1;k<=x;k++){
				if(j!=k){
					ac in;
					in.t=y[j].first+y[k].first;
					in.to=y[k].second;
//					cout<<in.t<<"*"<<in.to<<"__";
					g[y[j].second].push_back(in);
					in.to=y[j].second;
					g[y[k].second].push_back(in);
//					cout<<in.t<<"*"<<in.to<<"     ";
//					cout<<y[j].first<<" to "<<y[k].first<<" \n";
				}
			}
		}
//		cout<<"\n";
	}
//	for(int i=1;i<=id;i++){
//		cout<<i<<":";
//		for(ac j:g[i]){
//			cout<<j.t<<"_"<<j.to<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		ANS=1e18;
		for(int j:al[u]){
			vis.clear();
			ans=1e18;
			dfs(j,u,w[u]+w[v]+tak[j],v);
			ANS=min(ANS,ans);
		}
		cout<<ANS<<"\n";
	}
	return 0;
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
