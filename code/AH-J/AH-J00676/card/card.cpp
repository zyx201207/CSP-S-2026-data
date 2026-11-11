#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
long long sum[500005],f[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]++;
		b[a[i]]=max(b[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		sum[a[i]]+=f[i];
		f[b[a[i]]+1]+=f[i];
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",sum[i]);
	}
	return 0;
}
