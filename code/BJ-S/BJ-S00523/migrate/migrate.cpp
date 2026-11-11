#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10001],g[1001][1001]={0};
void dfs(int l,int h){
	for(int i=l;i<=n;i++){
		if(l!=1){
			if(l==n){
				g[l][0]++;
				g[l][g[l][0]]=h+1;
				return ;
			}
			if(x[i]-x[l]<=0){
				if(x[l]-x[i]<=d){
					g[l][0]++;
					g[l][g[l][0]]=h+1;
					dfs(l+i,h+1);
				}
			}
			else{
				if(x[i]-x[l]<=d){
					g[l][0]++;
					g[l][g[l][0]]=h+1;
					dfs(l+i,h+1);
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int q=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		dfs(1,0);
		for(int k=1;k<=n;k++){
			int d=9999,count=0;
			for(int j=1;j<=g[k][0];j++){
				if(g[k][j]<d){
					d=g[k][j];
					count=1;
				}
				if(g[k][j]==d){
					count++;
				}
			}
			if(count==2){
				q++;
			}
		}
		cout<<q<<endl;
		for(int j=1;j<=n;j++){
			g[j][0]=0;
		}
	}
	return 0;
}