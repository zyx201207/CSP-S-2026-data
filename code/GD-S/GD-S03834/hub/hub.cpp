#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,rk[1001],zt[501][1001],zx[1001][21]={0};
queue <int> gs;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,xs=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>rk[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int p=1;p<=k;p++){
			int a,t;
			cin>>a>>t;
			zt[i][a]=t;
			zx[a][i]=1;
		}
	}
	for(;q>0;q--){
		int x,y,t[1001];
		cin>>x>>y;
		
	}
	return 0;
} 
