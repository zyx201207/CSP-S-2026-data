#include <bits/stdc++.h>
using namespace std;
long long n,sum = 0;
long long a;
string s,v,o;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for(int i = 0; i < n; i++){
		cin >> a ;
		cin >> v ;
		for(int j = 0; j < a; j++){
			s += v;
		}
	}
	for(int i = 0; i*2 < s.size(); i++){
		if(s[s.size()-1-i] != s[i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
