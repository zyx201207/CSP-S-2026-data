#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,rk[1001],zt[501][1001],zx[501][1001]={0};
queue <int> qe;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
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
			zx[i][a]=1;
		}
	}
	for(;q>0;q--){
		int x,y,t[1001],xl[1001]={0};
		cin>>x>>y;
		t[x]=rk[x];
		xl[x]=1;
		qe.push(x);
		while(!qe.empty()){
			int zz=qe.back();
			qe.pop();
			for(int i=1;i<=n;i++){
				if(zx[i][zz]){
					for(int p=1;p<=m;p++){
						if(!xl[p]&&zx[i][p]){
							t[p]=t[zz]+zt[i][zz]+zt[i][p];
							xl[p]=1;
							qe.push(p);
						}
					}
				}
			}
		}
		cout<<t[y]+rk[y]<<endl;
		while(!qe.empty())qe.pop();
	}
	return 0;
} 
