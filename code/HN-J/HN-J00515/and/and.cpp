#include <bits/stdc++.h>
using namespace std;
int vis[200010];
long long a[200010];
long long n,m;
long long d(long long l,long long m1){
	long long ans = 0;
	if(m1 == m){
		return l;
	}
	for(long long i = 0;i < n;i++){
		if(!vis[i]){
			if(ans <= l & a[i]){
				ans = l & a[i];
				vis[i] = 1;
				d(ans,m1 + 1);
			}
		}
		vis[i] = 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long ans = 0;
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
	}
	for(long long i = 0;i < n;i++){
		vis[i] = 1;
		ans = max(d(a[i],1), ans);
		vis[i] = 0;
	}
	cout << ans;
	return 0;
}
