#include<bits/stdc++.h>

using namespace std;

const int maxn = 200020;

int n,m;
int a[maxn];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,greater<>());
	int ans = a[1];
	for(int i = 2;i <= m;i++){
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
