#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500100;
int n,m,a[N],pre[N];
int now,l,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=1;
	pre[n+1]=pre[n];
	for(int i=1;i<=n;i++){
		now++;
		pre[i]=pre[i-1]+a[i];
		while(now*a[i]-(pre[i]-pre[l-1])>m) l++,now--;
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
