#include <bits/stdc++.h>
using namespace std;

string s;
int n, a[2*100002];
char c[2*100002];
int ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int tmp  = 0;
	for(int i = 1;i <= n;i++){
	//	cout << 99;
		while(a[i]--){
			s[++tmp] = c[i];
			cout << 99;
		}
	}
	int r = 1;
	while(r <= tmp/2){
		if(s[r] != s[tmp+1-r]){
			ans++;
		}
		r++;
	}
	cout << ans;
	return 0;
}
