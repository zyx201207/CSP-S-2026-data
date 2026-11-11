#include<bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
int n,m,a[114514*5],b[114514*5],p,ans;
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
}
void solve(){
	input();
	for(int i=1;i<=n;i++){
		while(a[i]*(i-p+1)-b[i]+b[p-1]>m) p++;
		ans=max(ans,i-p+1);
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
