#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
int x[500010],y[500010];
struct node{
	int a,t;
}ki[500010];
int x,y,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ki[j].a>>ki[j].t;
		}
	}
	while(q){
		cin>>x>>y;
		
	}
	return 0;
}
