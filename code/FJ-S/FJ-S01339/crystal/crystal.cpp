#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],k,ans,m1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i){
		s[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<n;++i){
		k=1;
		m1=m;
		for(int j=i+1;j<=n;++j){
			m1-=(j-i)*s[j-1];
			if(m1<0)
				break;
			++k;
		}
		ans=max(ans,k);
		if(n-i+1<=ans)
			break;
	}
	printf("%lld",ans);
	return 0;
}
