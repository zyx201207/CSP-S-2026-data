#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define ull unsigned ll
#define ll long long
using namespace std;
ll n,m,cnt,ans,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll i,first = 1;
	rep(i,1,n,1) cin>>a[i];
	sort(a + 1,a + n + 1);
	rep(i,1,n,1){
		cnt += a[i];
		while(a[i] * (i + 1 - first) > m + cnt) cnt -= a[first++];
		ans = max(ans,i - first + 1);
	}
	cout<<ans;
	return 0;
}

