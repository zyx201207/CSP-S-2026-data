#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
struct node {
	int s;
	char z;
};
int n;
node a[N];
signed main() {
	freopen("string.in", "r" ,stdin);
	freopen("string.out", "w" ,stdout);
	cin >> n;
	if (n == 1) {
		cout<<0;
		return 0; 
	}
	else if (n == 2) {
		int a1,a2;
		char c1,c2;
		cin>>a1>>c1>>a2>>c2;
		if (c1 == c2) {
			cout<<0;
			return 0;
		}
		string str;
		for (int i = 1;i <= a1;i++) {
			str += c1;
		}
		for (int i = 1;i <= a2;i++) {
			str += c2;
		}
		int ans = 0;
		for (int i = 0;i < (a1 + a2) / 2;i++) {
			if (str[i] != str[str.size() - i - 1]) ans ++;
		}
		cout<<ans<<"\n";
	}
	else if (n <= 2e3) {
		int sum = 0;
		string str = "";
		for (int i = 1;i <= n;i++) {
			cin >> a[i].s >> a[i].z;
			sum += a[i].s;
			for (int j = 1;j <= a[i].s;j++) {
				str += a[i].z;
			}
		}
		int ans = 0;
		for (int i = 0;i < sum / 2;i++) {
			if (str[i] != str[str.size() - i - 1]) ans++;
		}
		cout<<ans<<"\n";
	}
	else {
		int mid = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].s >> a[i].z;
			mid += a[i].s;
		}
		mid /= 2;
		queue<pair<int,char> >q1,q2;
		int sum = 0;
		for (int i = 1;i <= n;i++) {
			sum += a[i].s;
		}
		int hl = 0,hr = 0;
		char cl = 'a',cr = 'a';
		int ans = 0;
	}
	return 0;
}
