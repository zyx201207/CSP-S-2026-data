#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
int n;
long long m;
long long a[MAXN],b[MAXN];
int top;
int mx = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	bool yes1 = true;
	for (int i = 1;i <= n;i++){
		if (i > 1 && a[i]-a[i-1] != a[2]-a[1]){
			yes1 = false;
			break;
		}
	}
	if (yes1){
		int mid;
		if (n % 2 == 0){
			mid = n/2;
		}else{
			mid = n/2+1;
		}
		int l = mid-1,r = mid+1;
		int ans = 1;
		while (l > 0 || r <= n){
			bool ok2 = false;
			if (l > 0 && m >= (a[mid]-a[l])){
				m-=(a[mid]-a[l]);
				l--;
				ans++;
				ok2 = true;
			}
			if (r <= n && m >= (a[r]-a[mid])){
				m-=(a[r]-a[mid]);
				r++;
				ans++;
				ok2 = true;
			}
			if (!ok2){
				break;
			}
		}
		cout << ans;
	}else{
		if (n <= 5000){
			for (int k = 1;k <= n;k++){
				long long m2 = m;
				memset(b,0,sizeof b);
				top = 0;
				int mid = k;
				for (int i = 1;i <= n;i++){
					if (i == mid){
						continue;
					}
					b[++top] = abs(a[mid]-a[i]);
				}
				sort(b+1,b+1+top);
				int ans = 1;
				for (int i = 1;i <= top;i++){
					if (m2 >= b[i]){
						ans++;
						m2-=b[i];
					}else{
						break;
					}
				}
				mx = max(mx,ans);
			}
			cout << mx;
		}else{
			long long m2 = m;
			memset(b,0,sizeof b);
			top = 0;
			int mid = n/2+1;
			for (int i = 1;i <= n;i++){
				if (i == mid){
					continue;
				}
				b[++top] = abs(a[mid]-a[i]);
			}
			sort(b+1,b+1+top);
			int ans = 1;
			for (int i = 1;i <= top;i++){
				if (m2 >= b[i]){
					ans++;
					m2-=b[i];
				}else{
					break;
				}
			}
			mx = max(mx,ans);
			cout << mx;
		}
	}
}
