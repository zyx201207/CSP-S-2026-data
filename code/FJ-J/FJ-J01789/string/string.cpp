#include <bits/stdc++.h>

using namespace std;

struct str{
	int len;
	char c;
};
vector <str> a;
int n,i=1;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	a.push_back({0,'0'});
	cin >> n;
	for (int i=1;i<=n;i++) {
		int l;
		char h;
		cin >> l >> h;
		a.push_back({l,h});
	}
	while (i<n) {
		if (a[i].c==a[n].c) {
			i++;
			n--;
		}
		else {
			int q=min(a[i].len,a[n].len);
			ans+=q;
			if (a[i].len<a[n].len) {
				i++;
				a[n].len-=q;
			}
			else if (a[i].len>a[n].len) {
				n--;
				a[i].len-=q;
			}
			else {
				i++;
				n--;
			}
		}
	}
	cout << ans;
	return 0;
}