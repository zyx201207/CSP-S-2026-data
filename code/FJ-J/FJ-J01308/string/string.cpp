#include <bits/stdc++.h>
using namespace std;
long long n,a,x = 1,l,r,ans;
char b;
string s = "";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a >> b;
		for(long long j = 1;j <= a;j++){
			s += b;
		}
	}
	if(s.size() % 2 != 0){
		l = s.size() / 2;
		for(x = 1;x <= l;x++){
			if(s[l - x] != s[l + x]){
				ans++;
			}
		}
	}
	if(s.size() % 2 == 0){
		r = s.size() / 2;
		l = r - 1;
		for(x = 1;x <= l;x++){
			if(s[l - x] != s[r + x]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
