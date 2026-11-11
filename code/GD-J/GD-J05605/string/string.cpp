#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n,x,len,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x >> c;
		len += x;
		for(int j = 0;j < x;j++) s += c;
	}
	if(len % 2 == 1){
		for(int l = len / 2 - 1,r = len / 2 + 1;l >= 0 && r <= len - 1;l--,r++){
			if(s[l] != s[r]) ans++;
		}
	}
	if(len % 2 == 0){
		for(int l = len / 2 - 1,r = len / 2;l >= 0 && r <= len - 1;l--,r++){
			if(s[l] != s[r]) ans++;
		}
	}
	cout << ans;
	return 0;
}
