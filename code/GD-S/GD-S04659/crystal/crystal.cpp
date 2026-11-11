#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
long long ans,m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//int l = 1;int r = n;
	long long mid = n;
	while(mid>=ans) {
		int cnt=0;
		for(int i=mid-1; i>=1; i--) {
			cnt +=  a[mid] - a[i];
			if(cnt>m) {
				//cout<<ans<<"\n";
				ans = max(ans,mid-i);
				break;
			}
			ans = max(ans,mid-i+1);
		}
		mid--;
	}
	cout<<ans;
}
