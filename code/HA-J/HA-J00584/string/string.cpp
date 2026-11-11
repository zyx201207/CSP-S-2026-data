#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n , a[200010] ,  cnt = 0;
	string b;
	char c;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] >> c;
		for(int y = 1; y <= a[i]; y++){
			b += c;
		}
	}
	for(int i = 1;i <= n;i++){
		if(b[i] != b[n - i + 1]) cnt++;
	}
	cout << cnt;
	return 0;
}
