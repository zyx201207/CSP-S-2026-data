#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,maxn = 0;
	cin >> n >> m;
	vector<int>a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	int sum = 0, cnt = 0, start = 0;
	for(int i=1; i<n; i++) {
		int k = a[i] - a[i-1];
		cnt++,sum+=k*cnt;
		while(sum>m)
			sum-=(a[i]-a[start]),start++,cnt--;
		maxn = max(maxn,cnt+1);
	}
	cout<<maxn<<endl;
	return 0;
}
