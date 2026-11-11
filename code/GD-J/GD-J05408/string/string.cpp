#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10 ;
long long n,cnt,cnt1;
struct node{
	char ch ;
	long long s ;
}a[N];
string st ;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].s >> a[i].ch ;
		for(int j = 1;j <= a[i].s;j++) st += a[i].ch ;
		cnt += a[i].s ;
	}
	if(cnt%2 == 0) {
		for(int i = 0;i <= cnt/2-1;i++) {
			if(st[i] != st[cnt-1-i]) cnt1++;
		}
	}else {
		for(int i = 0;i <= (cnt-1)/2-1;i++) {
			if(st[i] != st[cnt-1-i]) cnt1++;
		}
	}
	cout << cnt1 ;
	return 0;
}
