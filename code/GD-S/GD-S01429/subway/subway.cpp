#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,d,q,zd[550],a[550][2000],js;
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		cin>>zd[i];
	}
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		for(int j=1;j<=b;j++){
			int c;
			cin>>c;
			cin>>a[i][c];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	return 0;
} 
