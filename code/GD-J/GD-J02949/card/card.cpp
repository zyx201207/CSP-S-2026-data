#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector <int> a(n+1);
	vector <int> cnt(m+1,0);
	for (int i=0;i<n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i=1;i<=m;i++) if (cnt[i] != 0) cout << cnt[i] << " ";
	cout << '\n';
	return 0;
}
