#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long l=0,d=1;
		for(int j=i-1;j>0;j--){
			l+=a[i]-a[j];
			if(l>m)
				continue;
			d++;
		}
		ans=max(ans,d);
	}
	printf("%lld",ans);
	return 0;
}
