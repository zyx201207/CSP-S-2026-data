#include <bits/stdc++.h>
using namespace std;
bool b[500005],d[500005];
int n,m,a[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n<=500){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++) b[j]=true,d[j]=true;
			for (int j=i+1;j<=n;j++){
				bool o=false;
				for (int k=i;k<j;k++){
					if (o) b[k]=false;
					else if (b[k]&&a[j]==a[k]){
						o=true;
						b[k]=false;
					}
				}
			}
			for (int j=i;j<=n;j++) if (b[j]&&d[a[j]]) c[a[j]]+=1,d[a[j]]=false;
		}
	}
	else{
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) d[j]=true;
			for (int j=i;j<=n;j++) if (d[a[j]]) c[a[j]]+=1,d[a[j]]=false;
		}
	}
	for (int i=1;i<=m;i++) printf("%d ",c[i]);
	return 0;
}
