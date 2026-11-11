#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x;
	char c;
}a[200010];
long long cnt[200010];
long long ans;
int main(){
	freopen("string.in","r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].c;
		cnt[a[i].c-'a'+1] += a[i].x;
		ans += a[i].x;
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		sum = max(sum,cnt[i]);
	}
	cout << ans - sum;
	return 0;
}
