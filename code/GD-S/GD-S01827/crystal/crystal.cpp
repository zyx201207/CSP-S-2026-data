#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,a[N],m,pre[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i] = pre[i-1]+a[i];
	int ans = 0;
	for(int i=1,j=0;i<=n;i++){
		while(j<i && a[i]*(i-j)-(pre[i]-pre[j])>m) j++;
		ans = max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
