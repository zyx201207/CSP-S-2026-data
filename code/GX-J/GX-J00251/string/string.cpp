#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,cnt = 0;
	string s = "";
	cin >> n;
	for(long long i = 0;i < n;i++){
		long long x;
		char c;
		cin >> x >> c;
		for(long long j = 0;j < x;j++){
			s += c;
		}
	}
	//cout << s;
	long long len = s.size();
	for(long long i = 0;i < len / 2;i++){
		if(s[i] != s[len - 1 - i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
