#include <bits/stdc++.h>
using namespace std;
pair<unsigned long long,int> f[200005];
unsigned long long a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	f[1].first = a[1];
	f[1].second = 1;
	for (int i = 2;i <= n;i++){
		f[i].first = a[i];
		f[i].second = 1;
		for (int j = i;j >= 1;j--){
			if ((f[j].first & a[i]) >= f[i].first && f[j].second+1 <= m){
				f[i].first = (f[j].first&a[i]);
				f[i].second = f[j].second+1;
			}
		}
	}
	cout << f[n].first;
	return 0;
}
