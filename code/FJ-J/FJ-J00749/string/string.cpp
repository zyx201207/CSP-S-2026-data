#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200005;
int n,a[maxn],ans,na[maxn],nn=1;
char c[maxn],nc[maxn];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	for(int i = 1;i <= n;i++) {
		if(c[i]==c[i-1]) {
			--nn;
			na[nn++] += a[i];
		}else{
			na[nn++] = a[i]; nc[nn-1]=c[i];
		}
	}--nn;
	int l = 1,r = nn;
	while(l < r){
		if(na[l] == na[r]) {
			if(nc[l]==nc[r]) {
				l++; r--;
			}else {
				ans += na[l];
				l++; r--;
			}
		}else if(na[l] < na[r]) {
			if(nc[l] == nc[r]) {
				na[r] -= na[l];
				l++;
			}else{
				na[r] -= na[l];
				ans += na[l];
				l++;
			}
		}else if(na[l] > na[r]) {
			if(nc[l]==nc[r]) {
				na[l] -= na[r];
				r--;
			}else{
				na[l] -= na[r];
				ans += na[r];
				r--;
			}
		}
	}cout<<ans;
	return 0;
} 
