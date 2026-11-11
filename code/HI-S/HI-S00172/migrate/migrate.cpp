#include<bits/stdc++.h>
using namespace std;
long long c,t;
const long long N=2000005;
long long n,d=0,a[N],ans,p;
void solve(){
	ans=0;
	scanf("%lld%lld%lld",&n,&d,&a[1]);
	for(long long i=2;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n-3;i++){
		if(a[i+3]-a[i]>d && a[i+3]-a[i]<=d*2){
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
