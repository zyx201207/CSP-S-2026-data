//crystal
#include<bits/stdc++.h>
using namespace std;
long long int n, m, a[500005], s[500005], minbat, l, r, oldmid, ans;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i] = s[i-1] + a[i];
	}
	l=1;r=n;
	for(int mid = n/2;;){
		minbat = 9000000000000000005;
		for(int i=mid;i<=n;i++){
			minbat = min((mid*a[i]) - (s[i] - s[i-mid-1]), minbat);
		}
		if(minbat > m){
			r = oldmid = mid;
			mid = (l+r)/2;
		} else if (minbat < m){
			l = oldmid = mid;
			mid = (l+r)/2;
		} else if (minbat == m){
			ans = mid;
			break;
		}
		if(l == r or oldmid == mid){
			ans = mid;
			break;
		}
	}
	cout << ans;
}
