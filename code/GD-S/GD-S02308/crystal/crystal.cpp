#include <bits/stdc++.h>
#define endl '\n'
#define lint long long
using namespace std;
const int N = 5e5+5;
const lint M = 1e18;

int n;
lint m,a[N];
lint s[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a+1,a+1+n);
	
	for(int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i];
		
	int ans = 1;
	for(int i = 2; i <= n; i++){
		int l = 1,r = i;
		while(l <= r){
			int mid = l + r >> 1;
			int L = i - mid + 1;
			if(a[i]*mid - (s[i]-s[L-1]) <= m){
				ans = max(ans,mid);
				l = mid + 1;
			}else r = mid - 1;
		}
	} 
	
	cout << ans << endl;
	return 0;
}
