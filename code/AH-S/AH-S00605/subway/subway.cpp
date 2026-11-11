#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k,a,x,y;

long long w[512345],t;

long long gl[511][511];

struct node{
	int pass;
	long long tm;
};

vector<node> pnt[512345];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>a>>t;
			pnt[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			gl[i][j]=(long long)2e15;
			if(i==j)gl[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)pnt[i].size();j++){
			for(int k=j+1;k<(int)pnt[i].size();k++){
				gl[pnt[i][j].pass][pnt[i][k].pass]=min(gl[pnt[i][j].pass][pnt[i][k].pass],pnt[i][j].tm+pnt[i][k].tm);
				gl[pnt[i][k].pass][pnt[i][j].pass]=gl[pnt[i][j].pass][pnt[i][k].pass];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gl[i][j]=min(gl[i][j],gl[i][k]+gl[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		gl[i][i]=0;
	}
	while(q--){
		cin>>x>>y;
		if(x==y){
			cout<<0<<"\n";
			continue;
		}
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<(int)pnt[x].size();i++){
			for(int j=0;j<(int)pnt[y].size();j++){
				ans=min(ans,gl[pnt[x][i].pass][pnt[y][j].pass]+pnt[x][i].tm+pnt[y][j].tm);
			}
		}
		cout<<(ans+w[x]+w[y])<<"\n";
	}
	return 0;
}
