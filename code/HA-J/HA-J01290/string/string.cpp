#include<bits/stdc++.h>
#define ll long long
#define N 100100

using namespace std;

ll n,a[N],he;
char c[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
	}
	ll l=1,r=n;
	for(int i = 1; i*2 <= n; ++i) {
		if(a[l]>a[r]) {
			ll ch=a[l]-a[r];
			he+=a[r];
			if(c[l]==c[r]) {
				he-=a[r];
			}
			r--;
			for(int j = r; j > l; --j) {
				if(a[j]<ch) {
					he+=a[j];
					ch-=a[j];
					if(c[j]==c[l]) {
						he-=a[j];
					}
					a[j]=0;
					r--;
				} else {
					he+=ch;
					if(c[j]==c[l]) {
						he-=ch;
					}
					a[j]-=ch;
					ch=0;
					break;
				}
			}
		} else if(a[r]>a[l]) {
			ll ch=a[r]-a[l];
			he+=a[l];
			if(c[l]==c[r]) {
				he-=a[l];
			}
			l++;
			for(int j = l; j < r; ++j) {
				if(a[j]<ch) {
					he+=a[j];
					ch-=a[j];
					if(c[j]==c[r]) {
						he-=a[j];
					}
					a[j]=0;
					l++;
				} else {
					he+=ch;
					if(c[j]==c[r]) {
						he-=ch;
					}
					a[j]-=ch;
					ch=0;
					break;
				}
			}
		}
		else {
			he+=a[l];
			if(c[l]==c[r]) {
				he-=a[l];
			}
			l++;
			r--;
		}
	}
	cout << he << "\n";
	return 0;
}
