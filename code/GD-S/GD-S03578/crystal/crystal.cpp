#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	d[0]=0;
	for(int i=1;i<n;i++){
		d[i]=d[i-1]+(a[i]-a[i-1])*i;
	}
	long long ans = 0;
	for(int i=0;i<n;i++){
		if(d[i]<=m) ans = i+1;
		else break;
	}
	printf("%lld",ans);
	return 0;
} 
