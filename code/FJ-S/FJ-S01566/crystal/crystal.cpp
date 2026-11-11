#include <bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define endl '\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define st first
#define nd second
//#define int long long
using namespace std;
using ll=long long;
using lld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int N=5e5+10;
const ll inf=1e18;
int n,ans;
ll a[N],s[N],m;
signed main(){
	FILE("crystal"),
	ios::sync_with_stdio(false),
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
//			cerr<<mid<<' ';
			if((ll)(i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid-1;
			else l=mid+1;
//			cerr<<endl;
		}
		ans=max(ans,i-l+1);
//		cerr<<l<<endl;
	}
	cout<<ans;
	return 0;
}
