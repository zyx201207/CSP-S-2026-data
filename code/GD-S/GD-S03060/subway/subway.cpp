#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ta,tt,x,y,ki[505],w[500005],t[500005][505];
long long dis[505][505];
vector<int>a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki[i];
		for(int j=1;j<=ki[i];j++){
			cin>>ta>>tt;
			a[ta].push_back(i);
			t[ta][i]=tt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e17;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		if(a[i].size()>=2){
			for(int j=0;j<a[i].size();j++){
				for(int k=j+1;k<a[i].size();k++){
					dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],(long long)t[i][a[i][j]]+t[i][a[i][k]]);
					dis[a[i][k]][a[i][j]]=min(dis[a[i][k]][a[i][j]],(long long)t[i][a[i][j]]+t[i][a[i][k]]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		long long ans=LLONG_MAX;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				ans=min(ans,(long long)w[x]+t[x][a[x][i]]+dis[a[x][i]][a[y][j]]+t[y][a[y][j]]+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
