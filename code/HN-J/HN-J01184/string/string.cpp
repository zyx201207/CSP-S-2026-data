#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2e5 + 5;

int n;
ll ans;

struct node{
	int a;
	char c;
}d[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> d[i].a >> d[i].c;
	for(int l = 1, r = n; l <= r; ){
		if(d[l].a < d[r].a) ans += ((d[l].c != d[r].c) ? d[l].a : 0), d[r].a -= d[l].a, l++;
		else if(d[l].a > d[r].a) ans += ((d[l].c != d[r].c) ? d[r].a : 0), d[l].a -= d[r].a, r--;
		else ans += ((d[l].c != d[r].c) ? d[l].a : 0), l++, r--;
	}
	cout << ans;
	return 0;
}
