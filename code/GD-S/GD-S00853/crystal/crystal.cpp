#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500005];
ll b[500005];
ll xgz,cnt=1,l=1,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i =1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		while((i-l)*b[i]+xgz>m&&l<i){
			xgz-=(a[i-1]-a[l++]);
		}
		xgz+=(i-l)*b[i];
		cnt=max(cnt,i-l+1);
	}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

