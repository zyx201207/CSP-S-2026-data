#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int n;
char s[N];
struct node{
	int value;
	char c;
}a[N];
int gcd(int x,int y){
	if(y == 0) return x;
	return gcd(y,x%y);
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int cnt;
	for(int i = 1;i <= n;i++){
		cin >> a[i].value>>a[i].c;
		if(i == 1){
			cnt = a[i].value;
		}else{
			cnt = gcd(cnt,a[i].value);
		}
	}
//	cout << cnt;
	int cnt_ = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= (a[i].value/cnt);j++){
			s[++cnt_] = a[i].c;
		}
		
	}
//	for(int i = 1;i <= cnt_;i++) 
	long long ans = 0;
	for(int i = cnt_/2;i >= 1;i--){
		int j = cnt_-i+1;
		if(s[i] != s[j]) ans++;
	}
	cout << ans*cnt;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
