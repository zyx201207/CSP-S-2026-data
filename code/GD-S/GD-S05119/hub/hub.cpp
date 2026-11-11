#include<bits/stdc++.h>
using namespace std;
int g[2000000][2000000],c,t,u,v,n,k,ans=0;
int main(){
	freopen("hub1.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			g[u][v]=1;
			g[v][u]=1;
		}
		cout<<n/k-1<<endl;
	}
}
