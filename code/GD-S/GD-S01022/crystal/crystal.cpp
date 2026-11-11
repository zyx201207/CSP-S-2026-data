#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,a[N],m,s[N],ans=1;
signed main(){
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
	int now=1;
	for(int i=1;i<=n;i++){
		while((i-now+1)*a[i]-(s[i]-s[now-1])>m)now++;
		ans=max(ans,i-now+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
