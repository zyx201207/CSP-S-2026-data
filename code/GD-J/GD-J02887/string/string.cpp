#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++){
		int x;
		char c;
		cin >> x >> c;
		for (int j = 1;j <= x;j++)
			s += c;
	}
	//cout << s << endl;
	long long temp = s.size();
	//cout << temp << endl;
	for (long long i = 0;i < (temp/2)+1;i++){
		if (i > temp-i-1)
			break;
		if (s[i] == s[temp-i-1])
			continue;
		else
			cnt++;
	}
	cout << cnt;
	return 0;
}
