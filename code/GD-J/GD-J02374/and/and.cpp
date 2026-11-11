#include<bits/stdc++.h>
using namespace std;
const long long N = 200000 + 5;
long long n,m,a[N],ans,x,f[N];
vector<long long> e[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++){
		long long x = a[i];
		f[i] = 1;
		int maxi = 0,maxn = 0;
		for(int k = 2;k <= m;k ++){
			maxn = 0;
			for(int j = 1;j <= n;j ++){
				if(a[j] & x > maxn && !f[j]){
					maxn = a[j] & x;
					maxi = j;
				}
			}
			x = maxn;
			f[maxi] = 1;
		}
		ans = max(ans,x);
	}
	cout << ans;
	return 0;
}
