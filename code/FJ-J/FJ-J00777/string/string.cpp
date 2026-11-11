#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200010];
char c[200010];
long long st,en;
char s,e;

void solve()
{
	cin >> n;
	long long sum = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i] >> c[i];
		sum += a[i];
//		if(i > 0 && c[i] == c[i-1]){
//			a[i-1] += a[i];
//			i--,n--;
//		}
	}
	if(sum <= 2 * 10000) {
		long long l , r;
		l = r = sum/2;
		if(sum % 2 == 0) r ++;
		long long ans = 0;
		string s;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<a[i];j++){
				s += c[i];
			}
		}
		for(;l>=0;){
			if (l == r){
				l--,r++;
				continue;
			} else{
				if(s[l] != s[r]) ans ++;
				l--,r++;
			}
		}
		cout << ans;
		return;
	}
	long long l = 0,r = n-1;
	long long st = 0,en = 0;
	char s,t;
	long long ans = 0;
	while(l<=r){
		if(st == en){
			if(l == r) {
				cout << ans;
				return;
			} else {
				st += a[l],en+=a[r];
				s = c[l],e = c[r];
				l++,r--;
			}
		} else if(st > en){
			en += a[r],e = c[r],r--;
		} else st += a[l] , s = c[l] , l++;
		long long exg = min(st,en);
		st-=exg,en-=exg;
		if(s == e) {
			continue;
		}
		else {
			ans += exg;
			if(en == 0) e = s;
			else s = e;
		}
	}
	cout << ans;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

