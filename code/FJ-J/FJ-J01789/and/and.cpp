#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<string> a;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	a.push_back(" ");
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		string s="";
		for (int j=0;j<30;j++) {
			s+=x%2+'0';
			x/=2;
		}
		a.push_back(s);
	}
	int i=29;
	for (;i>=0;i--) {
		int cnt=0;
		for (int j=1;j<=n;j++) {
			if (a[j][i]=='1') cnt++;
		}
		if (cnt>m) {
			i--;
			break;
		}
		else if (cnt==m) break;
	}
	for (int j=1;j<=n && n>m;j++) {
		if (a[j][i]=='0') {
			a.erase(a.begin()+j);
			n--;
		}
	}
	while (n>m && i>0) {
		for (;i>=0;i--) {
			int cnt=0;
			for (int j=1;j<=n;j++) {
				if (a[j][i]=='1') cnt++;
			}
			if (cnt>=m) {
				i--;
				break;
			}
		}
		for (int j=1;j<=n && n>m;j++) {
			if (a[j][i]=='0') {
				a.erase(a.begin()+j);
				n--;
			}
		}
	}
	long long p=1;
	for (int i=0;i<30;i++) {
		bool ok=1;
		for (int j=1;j<=n;j++) {
			if (a[j][i]=='0') {
				ok=0;
				break;
			}
		}
		if (ok) {
			ans+=p;
		}
		p*=2;
	}
	cout << ans;
	return 0;
}