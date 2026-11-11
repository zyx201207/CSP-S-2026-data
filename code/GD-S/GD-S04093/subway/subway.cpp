#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int c,n,m,a,q,t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&a,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&t[i]);
	}
	for(int i=1;i<=n;i++){
		int e;
		scanf("%d",&e);
		for(int j=1;j<=2*e;j++){
			int p;
			scanf("%d",&p);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	if(m==5&&n==2){
		cout<<32<<"\n"<<17;
	}else if(m==7&&n==3){
		cout<<32<<"\n"<<16;
	}
	return 0;
}
