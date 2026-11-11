#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=5e5+5;
struct plan{
	int x;
	int y;
}r[maxn];
struct subway{
	int a;
	int t;
};
int c,n,m,d,q;
int w[maxn];
int k[maxn];
vector<subway> used[maxn];
vector<int> root[maxn];
int f[maxn][maxn];
bool ok[maxn];
bool ak;
void dfs(int x,int y,int z){
	if(z==y){
		ak=true;
		return;
	}
	for(auto i:root[z]){
		for(auto j:used[i]){
			if(ok[x]) continue;
			ok[j.a]=true;
			dfs(x,y,j.a);
			if(ak==true){
				if(j.a!=y) f[x][y]+=j.t;
			}
			ok[j.a]=false;
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
        cin>>k[i];
		for(int j=1;j<=k[i];j++){
			subway x;
			cin>>x.a>>x.t;
			root[x.a].push_back(i);
			used[i].push_back(x);
		}		
	}
	for(int i=1;i<=q;i++) cin>>r[i].x>>r[i].y;
	for(int i=1;i<=m;i++){
	    for(int j=1;j<=m;j++){
	        dfs(i,j,i);
		}		
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			for(int k=1;k<=m;k++){
				if(k!=i&&k!=j) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int h=1;h<=m;h++){
		for(int i=1;i<=m;i++){
		    for(int j=1;j<=m;j++){
			    if(i==j) continue;
			    for(int k=1;k<=m;k++){
				    if(k!=i&&k!=j) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			    }
		    }
	    }
	}
	for(int i=1;i<=q;i++)	cout<<f[r[i].x][r[i].y]+w[r[i].x]+w[r[i].y]<<endl;
	return 0;
} 
