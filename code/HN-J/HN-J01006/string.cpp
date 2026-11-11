#include<bits/stdc++.h>
using namespace std;
long long n, a[200005];
char b[200005];
string s;
int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	cin >> n;
	int c = 0, d = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		if(a[i] == a[i - 1]){
			c++;
		}
	}
	if(c >= n - 1) d = 1;
	if(d == 1){
		for(int i = 1; i <= n; i++){
			s += b[i];
		}
	}else{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= a[i]; j++){
				s += b[i];
			}
		}
	}
	long long sum = 0;
	for(int i = 0; i * 2 < s.length(); i++){
		if(s[i] != s[s.length() - i - 1]){
			sum++;
		}
	}
	if(d == 1){
		cout << sum * a[1];	
	}else{
		cout << sum;
	}
	
}
