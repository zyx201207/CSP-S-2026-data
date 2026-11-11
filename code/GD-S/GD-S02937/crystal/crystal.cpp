#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dwn(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
#define ll long long
#define int long long
const int N=5e5+7;
int n;
ll m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=0,ans=0;ll sum=0;
	while(r<=n){
		++r;sum+=a[r];
		while(a[r]*(r-l+1)-sum>m)sum-=a[l++];
		ans=max(ans,r-l+1);
	}cout<<ans;
	return 0;
}
