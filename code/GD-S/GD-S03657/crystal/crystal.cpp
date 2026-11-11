#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
const int N=5e5+5;
int n,ans;
i64 m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		int now=i;
		i64 rem=m;
		for(int b=18;b>=0;--b){
			if(1<<b<=now&&rem>=(a[i]<<b)-(s[now]-s[now-(1<<b)])){
				rem-=(a[i]<<b)-(s[now]-s[now-(1<<b)]);
				now-=1<<b;
			}
		}
		ans=max(ans,i-now);
	}
	cout<<ans<<'\n';
}