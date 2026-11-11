#include<bits/stdc++.h>
using namespace std;
int c;
void solve1(){
	int n,m,d,q,w[405],a,t,dis[605][605];
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=604;++i){
		for(int j=1;j<=604;++j){
			dis[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;++i){
		int kk;
		cin>>kk;
		for(int j=1;j<=kk;++j){
			cin>>a>>t;
			dis[a][400+i]=t;
			dis[400+i][a]=t;
		}
	}
	for(int i=1;i<=601;++i){
		for(int j=1;j<=601;++j){
			for(int k=1;k<=601;++k){
				dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
	return ;
}
void solve2(){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
//	if(0<=c&&c<=6){
		solve1();
//	}
//	else if(7<=c&&c<=11){
//		solve2();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

