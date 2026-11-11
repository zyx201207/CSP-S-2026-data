#include<bits/stdc++.h>
using namespace std;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
const int N = 5e5+5;
int n;
ll m,a[N];
int main(){
	fre("crystal");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	ll cnt = 0;
	int l = 1,r = 1,ans = 1;
	while(l<=n){
		while(r<n&&cnt+(a[r+1]-a[r])*(r-l+1)<=m) cnt+=(a[r+1]-a[r])*(r-l+1),r++;
		ans = max(ans,r-l+1);
		cnt-=(a[r]-a[l]);
		l++;
	}
	cout << ans;
	return 0;
}
