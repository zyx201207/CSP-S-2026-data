#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e2+10,INF=1e18;
ll read(){
	ll x=0,sign=1;char opt=getchar();
	while(opt<'0'||opt>'9'){
		if(opt=='-'){sign=-1;}
		opt=getchar();
	}
	while(opt>='0'&&opt<='9'){
		x=x*10+(opt-'0');
		opt=getchar();
	}
	return sign*x;
}
void print(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9){print(x/10);}
	putchar(x%10+'0');
}
ll c,n,m,d,q,w[N],dist[2*N][2*N],v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=2*m;i++){for(int j=1;j<=2*m;j++){if(i!=j){dist[i][j]=INF;}}}
	for(int i=1;i<=m;i++){w[i]=read();}
	for(int i=1;i<=n;i++){
		int num=read();
		for(int j=1;j<=num;j++){
			int u,val;u=read();val=read();
			dist[u][m+i]=dist[m+i][u]=val;
		} 
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=2*m;k++){
				if(dist[i][k]!=INF&&dist[k][j]!=INF){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				//cout<<i<<" "<<j<<" "<<k<<" "<<dist[i][k]<<" "<<dist[k][j]<<"\n";
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=2*m;k++){
				if(dist[i][k]!=INF&&dist[k][j]!=INF){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				//cout<<i<<" "<<j<<" "<<k<<" "<<dist[i][k]<<" "<<dist[k][j]<<"\n";
				}
			}
		}
	}
	//我忘了弗洛伊德怎么写，不能先求出子状态，但是我搞两遍不就好了O.o 
	while(q--){
		int x,y;x=read();y=read();
		print(dist[x][y]+w[x]+w[y]);putchar('\n');
	}
	
} 
