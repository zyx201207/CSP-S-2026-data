#include <bits/stdc++.h>
using namespace std;
string s, c1, c2;
int n, a[200005], sum; 
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		long long t = a[i];
		for(int i = 1;i <= a[i];i++){
			s += c[i];
			
		}
	}
	
	sum /= 2;
	for(int i = 1;i <= sum;i++){
		c1+=s[i];
	}
	for(int i = n;i > sum;i--){
		c2+=s[i];
	}
	long long cnt = 0;
	for(int i = 1;i <= sum;i++){
		if(c1[i] == c2[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
