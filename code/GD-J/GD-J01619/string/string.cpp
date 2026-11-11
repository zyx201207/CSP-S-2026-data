#include<bits/stdc++.h>
using namespace std;
int n,a,cnt,x;
string c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		x += a;
		for(int j = 0;j < a;j++)s = s + c;
	}
	for(int i = 0;i < x / 2;i++){
		cnt += (int)(s[i] != s[x - i - 1]);
	}
	cout << cnt;
	return 0;
}
