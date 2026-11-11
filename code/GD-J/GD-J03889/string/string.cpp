#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10e6;
int n,ans = 0;
long long a[MAXN],l = 1;
char s[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		char b;
		cin >> a[i] >> b;
		for(int j = 1;j <= a[i];j++){
			s[l] = b;
			l++;
		}
	}
	l--;
	for(int i = 1;i <= l / 2;i++){
		if(s[i] != s[l+1-i]) ans++;
	}
	cout << ans;
	return 0;
}
