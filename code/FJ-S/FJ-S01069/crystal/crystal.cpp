#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ans=0;
ll m;
ll a[500010];
ll s[500010];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int r=1;
	for(int l=1;l<=n;l++){//区间左端点
		//全都变成a[r] 
		while(r<=n){
			ll sum=1ll*(r-l+1)*a[r];
			if(sum-(s[r]-s[l-1])>m)break;
			r++;
		}
		r--;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
