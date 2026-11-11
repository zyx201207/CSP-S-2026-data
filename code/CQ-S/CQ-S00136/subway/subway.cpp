#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],t[500005][25],f[500005];
struct node{
	int v,e;
};
long long mn=1e18;
vector<int>a[505];
vector<node>p[500005];
void dfs(int x,int y,int ii,long long ti){
	if(f[x]==1){
		return;
	}
	f[x]=1;
	if(x==y){
//		cout<<ti+w[y]+t[y][ii]<<" ";
		mn=min(mn,ti+w[y]+t[y][ii]);
		return;
	}
	for(int i=0;i<p[x].size();i++){
		if(p[x][i].e!=ii){
			dfs(p[x][i].v,y,p[x][i].e,ti+t[x][ii]+t[x][p[x][i].e]);
			f[x]=0;
		}
		else{
			dfs(p[x][i].v,y,ii,ti);
			f[x]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			if(j>1){
				p[x].push_back({a[i][a[i].size()-1],i});
				p[a[i][a[i].size()-1]].push_back({x,i});
			}
			a[i].push_back(x);
			t[x][i]=y;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int j=0;j<p[x].size();j++){
			if(!(j>0&&p[x][j-1].e==p[x][j].e)){
				mn=1e18;
				dfs(x,y,p[x][j].e,w[x]+t[x][p[x][j].e]);
				f[x]=0;
//				cout<<"  ";
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}


