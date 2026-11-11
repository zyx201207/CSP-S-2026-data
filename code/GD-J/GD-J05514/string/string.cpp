#include <bits/stdc++.h>
using namespace std;
long long n,a[200002],len,jo,s;
char b[200002];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		len += a[i];
	}
	jo = len%2;
	len /= 2;
	int f = 1;
	while (len > a[f]){
		len -= a[f];
		f++;
	}
	if (jo){
		if (len == a[f]){
			a[f+1]--;
		}else{
			a[f]--;
		}
	}
	int l=f,r=f;
	if (len >= a[f]/2){
		if (len != a[f]){
			a[f] -= (a[f]-len)*2;
		}
		r++;
	}else{
		l--;
	}
	while (l >= 1&&r <= n){
		if (a[l] == a[r]){
			if (b[l] != b[r]){
				s += a[l];
			}
			l--;
			r++;
		}else if (a[l] < a[r]){
			if (b[l] != b[r]){
				s += a[l];
			}
			a[r] -= a[l];
			l--;
		}else if (a[l] > a[r]){
			if (b[l] != b[r]){
				s += a[r];
			}
			a[l] -= a[r];
			r++;
		}
	}
	cout << s;
	return 0;
}
