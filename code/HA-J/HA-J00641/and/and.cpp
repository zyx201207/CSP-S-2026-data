#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m;
vector <int> v[35];
int ans;
void makeq () {
	for (int i = 0;i <= 30;i ++) v[i].clear();
	for (int i = 1;i <= n;i ++) {
		for (int j = 0;j <= 30;j ++) {
			if ((a[i]>>j) & 1) v[j].push_back(a[i]);
		}
	} 
}
int main () {
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++) {
		cin>>a[i];
	}
	makeq ();
	for (int i = 30;i >= 0;i --) {
		if (v[i].size() >= m) {
			ans += (1<<i);
			n = 0;
			for (int j = 0;j < v[i].size();j ++) {
				a[++ n] = v[i][j];
			}
			makeq();
		}
	}
	cout<<ans;
	fclose (stdin);
	fclose (stdout);
	return 0;	
}
