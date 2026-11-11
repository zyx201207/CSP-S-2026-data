#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	long long need=0, l=1, sum=0, ans=0;
	for(int i=1;i<=n;i++){
		need+=(a[i]-a[i-1])*sum;
		if(need>m){
			while(need>m){
				l++;
				need-=a[i]-a[l];
			}
			sum=i-l;
		}
		ans=max(ans, ++sum);
	}
	cout << ans;
	return 0;
}
