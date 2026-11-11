#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long vis[500005];
long long maxn = - 9999;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1 ; i <= n ; i ++){
		if(i == 1) vis[1] = a[1];
		vis[i] = vis[i-1] - a[i];
	}
	for(long long i = 2, j = 1; i <= n ; i ++){	
	long long as = 0;
		if((vis[i] - vis[j] +1 + m) <  as ){
			j ++;
			continue;
		}
		maxn = max(maxn,i - j+1);
	}
	cout << maxn;
	return 0;
}
