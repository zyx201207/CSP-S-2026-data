#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005];
long long b[500005],x[300005],k[300005],f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=x[a[i]];
		x[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if(!f[a[j]])k[a[j]]++,f[a[j]]=1; 
			if(b[j]>=i)j=b[j];
		}
		for(int j=1;j<=m;j++)f[j]=0;
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",k[i]);
	}
	return 0;
}

