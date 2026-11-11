#include<bits/stdc++.h>

using namespace std;

#define cin fin
#define cout fout

using ll=long long;

const int N=2e4+2;//看空间大小够不够!!!

int c,n,m,d,q;
int w[N];
ll dis[N][N];
int aa[N][2];

int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	
	for(int i=1;i<=1001;++i){
		for(int j=1;j<=1001;++j){
			dis[i][j]=2147483647/2;
		} 
	}
	//cout<<dis[1][1];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k,cnt=0;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			aa[++cnt][0]=x;
			aa[cnt][1]=y;
		}
		for(int j=1;j<=cnt;++j){
			for(int k=1;k<=cnt;++k){
				if(j==k) continue;
				int x=aa[j][0],y=aa[k][0];
				dis[x][y]=min(dis[x][y],(aa[j][1]+aa[k][1])*1LL);
			}
		} 
	}
	
	for(int k=1;k<=m;++k){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			} 
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	
	fin.close();
	fout.close();
	return 0;
}
