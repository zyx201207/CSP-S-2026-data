#include<bits/stdc++.h>
using namespace std;
long long n, a[200020], d ,f;
char c[200020];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		d += a[i];
		for(int j = 1; j <= a[i]; j++){
			s += c[i];
			
		}
	}
	for(int i = 0; i < d / 2; i++){
		
		if(s[i] != s[d - i - 1]){
			f++;
		}	
		
		
	}
	cout << f;
	return 0;
}
