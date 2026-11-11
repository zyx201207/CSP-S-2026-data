#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
int sum[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1e9;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]|a[i]);
	}
	for(int i=1;i<=n;i++){
		maxn=max(sum[i+m]-sum[i],maxn);
	}
	cout<<maxn;
	return 0;
}

