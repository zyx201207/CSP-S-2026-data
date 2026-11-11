#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;ll m;
int a[N];
int c[N];
int main(){
	bool f1=1,f2=1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i)f1=0;
		if(a[i]-a[i-1]!=a[2]-a[1]&&i>2)f2=0;
		c[i]=a[i]-a[i-1];
	}
	if(f1){
		ll ans=1;
		while(m>=0){
			m-=ans;
			ans++;
		}
		printf("%lld",ans-1);return 0;
	}
	if(f2){
		ll ans=1;
		ll xj=abs(a[2]-a[1]);
		while(m>=0){
			m-=xj*ans;
			ans++;
		}
		printf("%lld",ans-1);return 0;
	}
	
	if(n<=5000){
		sort(a+1,a+n+1);
		ll sum=m,ma=INT_MIN;
		for(int i=n;i>=2;i--){
		sum=m;
		ll ans=1;
		while(sum>=0&&i-ans+1!=0){
			ans++;
			sum-=(a[i]-a[i-ans+1]);
		}
		ma=max(ma,ans-1);
		}
		printf("%lld",ma);return 0;
	}
	sort(c+1,c+n+1);
	sort(a+1,a+n+1);
	ll ans=1;
	while(m>=0){
		ans++;
		m-=abs(a[ans]-a[ans-1]);
	}
	printf("%lld",ans-1);
	return 0;
}
