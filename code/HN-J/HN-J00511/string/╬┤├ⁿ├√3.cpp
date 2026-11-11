#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
int sum[200010];
signed main(){
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
		int sum=0;
		for(int j=i;j<=i+m;j++){
			sum=(sum|a[j]);
		}
		maxn=max(sum,maxn);
	}
	cout<<maxn;
	return 0;
}

