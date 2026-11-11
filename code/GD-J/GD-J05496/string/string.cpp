#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct QJ{
	int l, r;
	char c;
}a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int top = 1;
	long long cnt = 0;
	for(int i = 1; i <= n; i++){
		int x;
		char ch;
		cin >> x >> ch;
		a[i].l = top;
		top += x;
		a[i].r = top-1;
		a[i].c = ch;
		cnt += x;
	}
	int cnt2 = cnt;
	cnt/=2;
	int ans = 0;
	for(int i = 1; i <= n/2; i++){
		long long x = a[n-i+1].r-a[n-i+1].l+1 - (a[i].r-a[i].l+1);
		if(x < 0){
			ans -= x;
			if(a[i].c != a[n-i+1].c){
				ans+=a[n-i+1].r-a[n-i+1].l+1;
			}
			a[n-i+1].l += x;
			a[n-i].r += x;
			
		}else if(x > 0){
			ans += x;
			if(a[i].c != a[n-i+1].c){
				ans+=a[i].r-a[i].l+1;
			}
			a[i].r += x;
			a[i+1].l +=x;
		}
	}
	if(n%2 == 0 && cnt2%2==1) ans--;
	cout << ans;
	return 0;
}
