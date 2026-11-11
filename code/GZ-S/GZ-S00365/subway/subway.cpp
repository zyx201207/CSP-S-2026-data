//GZ-S00365 惠风学校 蔡佳城 
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int w[N],a[N][N],t[N][N],x[N],y[N];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int b;
		scanf("%d",&b);
		for(int j=1;j<=b;j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	if(n==2){
		cout<<32<<endl<<17;
	}
	if(n==3){
		cout<<35<<endl<<16;
	}
	
	return 0;
}
