#include<bits/stdc++.h>
using namespace std;
long long w[500005]={0};
long long k[500005]={0},a[500005][500005]={0},t[500005][500005]={0};
long long x[500005]={0},y[500005]={0};
long long vis[500005]={0};
long long c=0,n=0,m=0,d=0,q=0;
int dfs(int x,int y,long long vis[]){
	return 0;
}
int f(int x,int y){
	long long num=0;
	num+=w[x];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				dfs(x,y,vis);
			}
		}
	}
	return 0;
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
//		f(x[i],y[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
