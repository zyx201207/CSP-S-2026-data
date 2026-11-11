#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
long long ans;
int main() {
	ios::sync_with_stdio();cin.tie();cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> c[i];
	int al=a[1],ar=a[n];
	char cl=c[1],cr=c[n];
	for (int l=1,r=n;l<r;) {
		if (cr!=cl) {
			if (al<ar) {
				ans+=al;
				ar-=al;
				l++;
				al=a[l];cl=c[l];
			}else {
				if (al>ar) {
					ans+=ar;
					al-=ar;
					r--;
					ar=a[r];cr=c[r];
				}else {
					if (al==ar) {
						ans+=al;
						l++;r--;
						al=a[l];cl=c[l];
						ar=a[r];cr=c[r];
					}
				}
			}
		}else {
			if (al<ar) {
				ar-=al;
				l++;
				al=a[l];cl=c[l];
			}else {
				if (al>ar) {
					al-=ar;
					r--;
					ar=a[r];cr=c[r];
				}else {
					if (al==ar) {
						l++;r--;
						al=a[l];cl=c[l];
						ar=a[r];cr=c[r];
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
