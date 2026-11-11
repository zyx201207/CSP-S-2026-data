#include<bits/stdc++.h>
using namespace std;
const int MAXM=20000;

int e[MAXM][MAXM],T[600][MAXM],C[MAXM];
unordered_map<int,int> mp;
unordered_map<int,int> mp2;
int c,n,m,d,q,W[MAXM];
int k[600];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int u,last_t;
		cin>>u>>last_t;
		if(mp[u]){
			C[u]=1;
		}
		mp[u]++;
		T[i][u]=last_t;
		for(int j=2;j<=k[i];j++){
			int v,t;
			cin>>v>>t;
			if(mp[v]){
				C[v]=1;
			}	
			mp2[u]=i;
			mp2[v]=i;
			mp[v]++;
			T[i][v]=t;
			e[u][v]=0;
			e[v][u]=0;
			u=v;
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(e[i][k]+e[k][j]<e[i][j]){
					if(C[k]){
						if(e[i][j]>=0x3f3f3f3f){
							e[i][j]=T[mp2[j]][k];
							
						}
					}
					else{
						e[i][j]=e[i][k]+e[k][j];
					}
				}
			}
		}
	}
//	for(int i=0;i<=m;i++){
//		for(int j=0;j<=m;j++){
//			if(!i) cout<<j;
//			else if(!j) cout<<i;
//			else cout<<e[i][j];
//			cout<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<e[x][y]+W[x]+W[y]<<endl;
	}
//	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}
