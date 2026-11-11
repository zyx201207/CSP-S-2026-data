#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int st[N];
int n,m;
bool fs(int x) {
	for (int i = 1;i <= n;i++) {
		if (st[i] == x && st[i] != 0) {
			return false;
		}
	}
	return true; //ц╩сп 
}
void del(int pos) {
	for (int i = pos;i <= n;i++) {
		st[i] = 0;
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int res[N];
	int kp = 0;
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			int now;
			if (a[j] == 0) continue;
			else {
				now = a[j];
			}
			if (fs(now) == 1) {
				st[i] = now;
			    //res[i]++;
			    if (i < kp) {
			    	continue;	
				}
				else { 
					res[i]++;
				}
			}
			else {
				del(now);
				kp = i - 1;
			}
		}
	}
	for (int i = 1;i <= m;i++) {
		cout << res[i] << " ";
	}
}
