#include <bits/stdc++.h>
#define maxn 500005
#define int long long
using namespace std;
int n,m,sum,now,ans,a[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int l=1,r=2;r<=n;r++){
		while(l!=r&&(a[r]-a[r-1])*(r-l)+now>m) l++,now-=(a[r-1]-a[l-1]);
		now+=(a[r]-a[r-1])*(r-l);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	cout.flush();
}
