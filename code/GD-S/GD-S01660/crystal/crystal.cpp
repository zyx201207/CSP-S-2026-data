#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define REP(i,x,y) for(int i=(x);i>=(y);i--)
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
const int N=500003;
int n;
ll m,a[N],s[N];
signed main(){
	fastIO;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int l=1,ans=0;
	rep(i,1,n){
		while(l<i&&1ll*a[i]*(i-l+1)-(s[i]-s[l-1])>m) ++l;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
