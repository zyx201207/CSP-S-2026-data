#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100001],x,y,a[5001][20],t[5001][20],k[501],s,mm=100000001;
void ss(int x,int tt,int u){
	if(x==y){
		mm=min(tt,mm);
		return ;
	}
	if(tt>=mm){
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
		    if(a[j][i]==x){
				if(i!=u){
					ss(a[j+1][i],t[j][i]+tt+t[j+1][i],i);
				}else{
					ss(a[j+1][i],t[j+1][i]+tt,u);
				}
		    	
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
    	scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[j][i],&t[j][i]);
		}
	}
	for(int i=1;i<=q;i++){
    	scanf("%d%d",&x,&y);
    	ss(x,w[x]+w[y],0);
    	printf("%d\n",mm);
    	mm=100000001;
	}
	return 0;
} 
