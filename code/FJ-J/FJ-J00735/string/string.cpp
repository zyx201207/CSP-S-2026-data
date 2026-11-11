#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n;
pair<int, int> a[N], b[N];
char s[N], s_[N];
int sum;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	int pre = 1;
	for (int i = 1; i <= n; i++){
		int l;
		scanf("%lld %c", &l, &s[i]);
		a[i] = {pre, pre+l-1};
		s_[n-i+1] = s[i];
		sum += l;
		pre = pre+l;
	}
	pre = 1;
	for (int i = 1; i <= n; i++){
		int j = n-i+1;
		int l = a[j].second - a[j].first+1;
		b[i] = {pre, pre+l-1};
		pre = pre + l;
	}
	int cnt = 0;
	int mid;
	if (sum%2) mid = (sum-1)/2;
	else mid = sum/2;
	for (int i = 1, j = 1; b[i].first <= mid && i <= n && j <= n; i++){
		int l = b[i].first;
		int r = b[i].second;
		if (r > mid){
			r = mid;
		}
		while (a[j].second < l && j <= n) j++;
		pre = l;
		while (a[j].first <= r && j <= n){
			if (a[j].second > r){
				if (s[j] != s_[i]){
					cnt += r-pre+1;
				}
				break;
			}else{
				if (s[j] != s_[i]){
					cnt += a[j].second-pre+1;
				}
				pre = a[j].second+1;
				j++;
			}
		}
	}
	printf("%lld", cnt);
	return 0;
}
