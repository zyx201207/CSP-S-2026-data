#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[10005],sum = 0;
	string s = "",c[10005];
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for (int j = 1;j <= a[i];j++){
			s += c[i];
		}
	}
	long long l = s.size();
	for (int i = 0;i < l;i++){
		if (s[i] != s[l - i - 1]){
			sum++;
		}
	}
	cout << sum/2;
	return 0;
}