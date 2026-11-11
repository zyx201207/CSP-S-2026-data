#include<bits/stdc++.h>
using namespace std;
int a[500005];
int vis[300005];
int c[300005];
int g[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		int nl=0; 
		for(int i=k;i<=n;i++){
			if(vis[a[i]]!=0){
				while(nl>vis[a[i]]){
					vis[g[nl]]=0;
					g[nl]=0;
					nl--;
				}
			}
			else{
				nl++;
				vis[a[i]]=nl;
				g[nl]=a[i];
			}
		}
		for(int i=1;i<=nl;i++){
			c[g[i]]++;
			vis[g[i]]=0;
			g[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
