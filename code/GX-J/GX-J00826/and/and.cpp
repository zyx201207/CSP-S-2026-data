#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1,ma,x,f[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
scanf("%lld",&n);
scanf("%lld",&m);
for(long long i=1;i<=n;i++){
		scanf("%lld",&x);
		f[i]=x;
}
for(long long i=1;i<=n;i++){
	for(long long j=1;j<=m;j++){
		ma=f[i]^f[j];
		ans=max(ma,ans);
cout<<ans;
return 0;
}
}
}

	

