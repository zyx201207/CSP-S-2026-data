#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],b[500100],c[500100],ans[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int cnt=0;
		for(int j=i;j<=n;j++){
			++cnt;
			if(b[a[j]]){
				int z=b[a[j]];
				c[cnt]=a[j];
				for(int k=b[a[j]];k<=cnt;k++) b[c[k]]=0;
				cnt=z-1;
			}
			else{
				b[a[j]]=cnt;
				c[cnt]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]) ans[j]++;
		}	
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
