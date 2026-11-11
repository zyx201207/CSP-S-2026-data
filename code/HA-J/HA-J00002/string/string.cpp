#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,a[N];char c[N];
ll pre[N],suf[N],ans;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	fre("string");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>c[i];
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	for(int i=n;i>=1;--i)suf[i]=suf[i+1]+a[i];
	ll l=1,r=n,len=0;
	while(l<r&&len<pre[n]/2){
		ll a = pre[l]-len,b=suf[r]-len;
		if(c[l]!=c[r])ans+=min(a,b);
		if(a==b)++l,--r;
		else if(a<b)++l;
		else --r;
		len+=min(a,b);
	}
	cout<<ans;
	return 0;
}
