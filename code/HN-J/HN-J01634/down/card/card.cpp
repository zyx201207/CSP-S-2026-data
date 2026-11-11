#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			if(b[a[j]]!=0) for(int k=b[a[j]];k<=j;k++) b[c[k]]=0,c[k]=0;
			b[a[j]]=j;
			c[j]=a[j];
		}
		for(int j=1;j<=n;j++) if(b[a[j]]!=0) sum[a[j]]++,b[a[j]]=0,c[j]=0;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
} 
