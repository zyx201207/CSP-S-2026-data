#include <bits/stdc++.h>
using namespace std;

long long n,len = 0,diff;
int a[200010];
char c[200010];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		len += a[i];
		s += string(a[i],c[i]);
	}
	for(int i = 0;i < len / 2;i++){
		if(s[i] != s[len - i - 1])diff++;
	}
	cout << diff;
	

	return 0;
}
