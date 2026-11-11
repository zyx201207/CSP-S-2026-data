#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,a[N],m;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i<=n; i++)cin>>a[i];
	int maxx = -1e9;
	for(int i = 1; i<=n; i++) {
		int andl = a[i];
		for(int j = 1; j<=m-1; j++) {
			andl = a[i]&a[j];
		}
		maxx = max(maxx,andl);
	}
	cout<<maxx;
	return 0;
}

