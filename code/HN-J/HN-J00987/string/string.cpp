#include <bits/stdc++.h>
using namespace std;
char s[10000000],a;long long n,x,cnt = 0,tot = -1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> x >> a;
		for (int i = 1;i <= x;i++){
			tot++;
			s[tot] = a;
		}
		
	}
	for (int i = 0;i <= tot/2;i++){
		if (s[i] != s[tot - i ]){
			cnt++;
		}
	}
	cout << cnt;
	return 0; 
} 
