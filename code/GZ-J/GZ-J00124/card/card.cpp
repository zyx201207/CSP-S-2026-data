// 遵义市第四中学 杨浩辰 GZ-J00124 
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#define f front
#define w back 
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N], t[N], s[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t[a[i]]=i; 
		s[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		cout << t[i]*(s[i]%2) << " ";
	}
	return 0;
}
