#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
long long a[N];
char s[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for(long long i = 1; i <= n; i++)cin >> a[i] >> s[i];
	long long l = 1, r = n;
	long long cnt = 0;
	while(l < r){
		if(s[l] == s[r]){
			if(a[l] >= a[r]){
				a[l] -= a[r];
				r--;
			}else{
				a[r] -= a[l];
				l++;
			}
		}else{
			if(a[l] >= a[r]){
				a[l] -= a[r];
				cnt += a[r];
				r--;
			}else{
				a[r] -= a[l];
				cnt += a[l];
				l++;
			}
		}
	}
	cout << cnt; 
	return 0;
}

