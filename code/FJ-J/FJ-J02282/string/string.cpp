#include<bits/stdc++.h>
using namespace std;

int n;
long long ans = 0,a[200010];
char c[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	int l = 1,r = n;
	while(l < r){
		if(c[l] != c[r]){
			ans += min(a[l],a[r]);
		}
		if(a[l] < a[r]){
				a[r] -= a[l];
				l++;
				continue;
			}
			if(a[l] == a[r]){
				l++;
				r--;
				continue;
			}
			if(a[l] > a[r]){
				a[l] -= a[r];
				r--;
				continue;
			}	
	}
	cout << ans;
	return 0;
}
