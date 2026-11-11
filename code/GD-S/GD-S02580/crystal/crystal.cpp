#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int l = 1,ans = 1,cnt = 0;
	for(int i = 2;i <= n;i++){
		cnt = cnt + (i - l) * (a[i] - a[i-1]);
		while(l <= i && cnt > m){
			cnt -= (a[i] - a[l]);
			l++;
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans;
	return 0;
} 
