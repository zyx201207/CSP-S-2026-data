#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c,n,m,d,q,w[N],t[510][510],a[510][510],k[N];
bool s,flag;
int main(){
	freopen("subway.cpp","r",stdin);
	freopen("subway.cpp","w",stdout);
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
	int u,v;
	while(q--){
		cin>>u>>v;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(u==a[i][j]) flag=1;
				if(v==a[i][j]) s=1;
			}
			if(s==1&&flag==1) cout<<w[u]+w[v]+t[i][u]+t[i][v]<<endl;
		}
	}
	return 0;
} 
