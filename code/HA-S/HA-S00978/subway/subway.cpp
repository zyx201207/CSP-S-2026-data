#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,ti,l,r;
int w[500005],t[500005][505];
vector<int> a[500005];
vector<int> b[505];
bool v[500005];
void dfs(int xx,int yy,int tt){
	if(xx==yy){
		ti=min(ti,tt);
		return ;
	}
	if(tt>=ti){
		return ;
	}
	for(int i=0;i<a[xx].size();i++){
		for(int j=0;j<b[a[xx][i]].size();j++){
			if(v[b[a[xx][i]][j]]==0){
				v[b[a[xx][i]][j]]=1;
				dfs(b[a[xx][i]][j],yy,tt+t[xx][a[xx][i]]+t[b[a[xx][i]][j]][a[xx][i]]);
				v[b[a[xx][i]][j]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>x;
			a[x].push_back(i);
			b[i].push_back(x);
			cin>>t[x][i];
		}
	}
	while(q--){
		memset(v,0,sizeof v);
		cin>>l>>r;
		ti=1e9;
		v[l]=1;
		dfs(l,r,0);
		cout<<ti+w[l]+w[r]<<"\n";
	}
	return 0;
} 
