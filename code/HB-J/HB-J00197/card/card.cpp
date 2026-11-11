#include<bits/stdc++.h>
using namespace std;
const int M=3e5*10;
int a[M],b[M],d[M],n,m;
int c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++){
			c[j]=a[i];
			for(int k=j-1;k>=i;k--){
				if(c[j]==c[k]);
				for(int q=k;q<=j-1;q++)c[q]=0;
				}
			}
		for(int j=1;j<=n;j++)b[c[j]]++;
		for(int j=1;j<=n;j++)if(b[j])d[j]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",d[i]);
	return 0;
}
