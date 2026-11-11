#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],c[300001],d[500001],e[500001],f[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
		d[i]=c[a[i]];
		e[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(d[i]<c[a[i]]){
			for(int j=i+1;a[j]!=a[i];j++)
				e[j]-=e[i];
			e[i]=0;
		}
		f[a[i]]=max(f[a[i]],e[i]);
	}
	for(int i=1;i<=m;i++) printf("%d ",f[i]);
	return 0;
}
