#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
int k[M];
int w[M];
struct node{
	int a,t;
};
node at[505][M];
int sum=0;
void cf(int u,int v){
	if(u==v){
		sum+=w[v];
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(at[i][j].a==u){
				if(j==1){
					sum=sum+at[i][j].t+at[i][at[i][2].a].t;
					cf(at[i][2].a,v);
				}else{
					sum=sum+at[i][j].t+at[i][at[i][1].a].t;
					cf(at[i][1].a,v);
				}
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=n;j++){
			cin>>at[i][j].a>>at[i][j].t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		sum=w[x];
		cf(x,y);
		cout<<sum<<"\n";
	}
	
	
	
	
	return 0;
} 
