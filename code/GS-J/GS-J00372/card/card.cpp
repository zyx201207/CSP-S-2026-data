#include<bits/stdc++.h>
using namespace std;
int a[500010],b[100010];
bool vis[500010];
	int n,m;
void dfs(int x){
	 for(int i=1;i<=m;i++){
	 	int wjy,joy;
	 	bool flag=false;
	 	for(int j=x;j<=n;j++){
	 		if(a[j]==i){
	 		  wjy=j;
	 		  break;
			   }
		 }
		for(int j=x;j<=n;j++){
			if(a[j]==i&&j!=wjy){
	 		       joy=j;
	 		       flag=true;
	 		   }
		}
		if(flag==true){
	    for(int j=wjy;j<joy;j++)
	        vis[j]=1;
	    }
	 }
	 for(int j=x;j<=n;j++)
	        if(vis[j]!=1){
	           b[a[j]]++;
	       }
	memset(vis,0,sizeof(0));
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
			dfs(i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
