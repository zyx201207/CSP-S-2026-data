#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5,N=5e5+5;
int n,m,last=0;
int vis[M];
int a[N],b[N];
long long ans[M];
void clear(int x){
	for(int i=x;i<=last;i++) vis[b[i]]=0;
	for(int i=x;i<=last;i++) b[i]=0;
	last=vis[b[x-1]];
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				last++;
				vis[a[j]]=last;
				b[last]=a[j];
				
				
			}else{

				
				clear(vis[a[j]]);
				
				
				last++;
				vis[a[j]]=last;
				b[last]=a[j];
				
			
				
			}
		}
		for(int i=1;i<=m;i++) if(vis[i]>0) ans[i]++;
		
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		last=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
