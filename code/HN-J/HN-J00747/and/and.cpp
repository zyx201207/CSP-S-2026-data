#include<bits/stdc++.h>
#define endl '\n';
using namespace std;

long long n,m,a[200050],ans,vis[200050];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(long long i = 29;i >= 0;i --){
		long long c = 0;
		for(long long j = 1;j <= n;j ++){
			long long k = a[j] & (1ll << i);
			if(k && !vis[j]){
				c ++;
			}
		}
		if(c >= m){
			for(long long j = 1;j <= n;j ++){
				long long k = a[j] & (1ll << i);
				if(!k){
					vis[j] = 1;
				}
			}
			ans += 1ll << i;
		}
	}
	cout << ans;
	return 0;
}

