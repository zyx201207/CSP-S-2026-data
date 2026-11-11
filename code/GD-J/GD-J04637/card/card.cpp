#include<bits/stdc++.h> 
using namespace std;
const int N=500010;
int a[N],b[N],c[N],ans[N],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b)); 
		memset(b,0,sizeof(b)); 
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				c[a[j-1]]=a[j];
			}
			else{
				int u=a[j];
				while(c[u]){
					b[c[u]]=0;
					u=c[u];
				}
				c[a[j]]=0;
			}
		}
		for(int j=1;j<=m;j++)
		    if(b[j]){
		    	ans[j]++;
			}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
