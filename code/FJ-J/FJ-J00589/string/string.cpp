#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
string s;
char c[MAXN];
unsigned long long ans = 0,n,a[MAXN],len_s= 0,t = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0;i < n ; i ++){
		cin >> a[i] >> c[i];
		for(int j = t;j < t + a[i];j ++)
			s[j] = c[i];
		t += a[i];
	}
	for(int i = 0;i < t/2;i++){
		if(s[i] != s[t-1-i]) ans++;
	}
	cout << ans;
	return 0;
}
