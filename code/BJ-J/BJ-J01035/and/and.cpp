#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int N=2*1e5+10;
int n, m;
long long maxs;
long long a[N];
bool t[N][31];
bool b[N];
int ans;
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		maxs=max(a[i], maxs);
	}
	int p=floor(log2(maxs))+1;
	//cout << p;
	for (int i=1;i<=n;i++) {
		int x=a[i];
		int post=1;
		while (x) {
			t[i][post++]=x%2;
			x/=2;
		}
		//for (int j=1;j<=p;j++) cout << t[i][j];
		//cout << ' ';
	}
	for (int i=p;i>=1;i--) {
		int k=0;
		for (int j=1;j<=n;j++) {
			if (!b[j]&&t[j][i])k++;
		}
		if (k>=m) {
			for (int j=1;j<=n;j++) {
				if (t[j][i]==0) b[i]=true;
				//cout << t[j][i]<<i<< ' ';
			}
			ans+=pow(2, i-1);
			//cout << ans << endl;
		}
	}
	cout << ans;
	return 0;
}