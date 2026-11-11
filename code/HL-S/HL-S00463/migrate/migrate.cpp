#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inline ret() {
	ll t=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		t=t*10+ch-'0';
		ch=getchar();
	}
	return f*t;
}
ll C,T;
ll n,m;
ll a[2000009];
ll dfs(ll p,ll tim,const ll to){
	if(tim<0||to-tim*m>p) return 0;
	if(p>to) return 0;
	if(p==to&&tim==0) return 1;
	int sum=0;
	for(ll i=p+1;a[i]<=a[p]+m;i++){
		sum+=dfs(i,tim-1,to);
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=ret();T=ret();
	while(T--){
		n=ret();m=ret();
		for(ll i=1;i<=n;i++){
			a[i]=ret();
		}
		ll sans=0;
		for(ll i=1;i<=n;i++){
			ll ans=0;
			for(ll j=i+3;j<=n;j++){
				if(ans&&a[j]-a[j-1]<=m&&a[j]-a[j-2]>m) {
					ans++;
					continue;
				} else if(ans){
					break;
				}
				if(a[j]-a[i]<=m) continue;
				ll tim=1;
				for(ll p=i;p<j;tim++){
					p=upper_bound(a+i,a+j+1,a[p]+m)-a;
				}
				//cout<<i<<" "<<j<<" "<<tim<<endl;
				int t=dfs(i,tim,j);
				if(t==2){
					ans++;
				} else if(t>2) break;
			}
			sans+=ans;
		}
		printf("%lld\n",sans);
	}
	return 0;
}
