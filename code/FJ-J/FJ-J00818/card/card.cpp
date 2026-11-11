#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],b[500005],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		k=0;
	//	cout<<k;
		for(int j=i;j<=n;j++){
			k=find(b+1,b+k+1,a[j])-b;
			b[k]=a[j];
		}
		for(int j=1;j<=k;j++){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",t[i]);
	return 0;
} 
