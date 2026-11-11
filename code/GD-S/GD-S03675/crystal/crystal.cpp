#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
long long n,m,maxx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		long long k;
		for(long long j=1;j<=n;j++){
			k+=b[i+j-1]*j;
			if(k>m){
				maxx=max(maxx,j);
				break;
			}
		}
		k=0;
	}
	printf("%lld",maxx);

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
