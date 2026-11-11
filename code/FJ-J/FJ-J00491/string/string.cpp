#include <bits/stdc++.h>
using namespace std;
char s[1000000000];
int num[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long len = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		char c;
		cin >> a >> c;
		len += a;
		if(len >= 1000000000){
			cout << 0 << endl;
			return 0;
		}
		num[i] = a;
		for(int j = num[i-1]+1; j <= a; j++){
			s[i] = c;
		}
	}
	long long cnt = 0;
	for(int i = 0; i <= ceil((len-1)/2.0); i++){
		if(s[i] != s[len-1-i]) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
