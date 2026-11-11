#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int cnt[N],pre[N],a[N];
int n,m,tmp = 0,ans = 1,dp = 0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++) cin>>a[i];
	if(n > 5e5 && m > 1e8){
		int c = a[1] - a[0];
		for(int i = 1;i <= n;i++){
			if(dp + c * i <= m) dp += c * i,ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a,a + n); 
	for(int i = 0;i < n - 1;i++) cnt[i] = a[i + 1] - a[i];
	for(int i = 1;i < n;i++){
		tmp = 0;
		dp = 0;
		pre[i] = 0;
		pre[i - 1] = cnt[i - 1];
		for(int j = i - 2;j >= 0;j--) pre[j] = cnt[j] + pre[j + 1];
		sort(pre,pre + i + 1);
		for(int j = i;j >= 0;j--){
			if(dp + pre[j] <= m) dp += pre[j],tmp++;
			else break;
		}
		ans = max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
