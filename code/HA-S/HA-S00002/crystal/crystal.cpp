#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],sum; int ans;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	fre("crystal");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int l=1,r=1;r<=n;++r){
		sum+=a[r];
		while(a[r]*(r-l+1)-sum>m)sum-=a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
