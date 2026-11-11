#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N(5e5+5);
int n;
ll m,a[N],s[N];
int ans(0);
int sol(int l,int r,int pos){
	int res(n);
	for(;l<=r;){
		int mid(l+((r-l)>>1));
		if((s[pos]-s[mid-1]+m)>=1ll*a[pos]*(pos-mid+1)){
			r=mid-1;
			res=mid;
		}else l=mid+1;
	}return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i(1);i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i(1);i<=n;++i) s[i]=s[i-1]+a[i];
	for(int i(1);i<=n;++i) ans=max(ans,i-sol(1,i,i)+1);
	cout<<ans<<"\n";
	return 0;
}
