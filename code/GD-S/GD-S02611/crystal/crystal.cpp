#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],ans,s[500100],j,l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		l=0;r=i;
		while(l+1<r){
			long long mid=l+(r-l)/2;
			if(s[i]-s[mid-1]+m<(i-mid+1)*a[i]) l=mid;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
