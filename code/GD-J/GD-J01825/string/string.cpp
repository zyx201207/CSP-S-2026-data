#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n;
	cin >> n;
	long long m = 0;
	long long num;
	string c;
	string s;
	for(long long i=0;i<n;i++){
		cin >> num >> c;
		while(c.size() < num){
			c = c+c;
		}
		for(int j=c.size();j>=num;j--){
			c.erase(j);
		}
		s = s+c;
	}
	long long x = 0;
	n = s.size();
	n = n/2+n%2;
	for(int i=0;i<n-1;i++){
		x += (s[i] != s[i+n]);
	}
	cout << x;
	return 0;
} 
