#include <bits/stdc++.h>
using namespace std;
long long s[200005];
string c[200005];
int main(){
	freopen("string.in","r", stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> c[i];
	}
	long long l = 1, r = n;
	long long num = 0;
	while(l < r){
		if(c[l] != c[r]){
			num += min(s[l], s[r]);
			if(s[l] <= s[r]){
				s[r] -= s[l];
				l++;
			}
			else{
				s[l] -= s[r];
				r--;
			}
		}
	}cout << num;
	return 0;
}
