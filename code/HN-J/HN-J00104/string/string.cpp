#include<bits/stdc++.h>
using namespace std;
long long a[20000005], sum;
long long n;
string s, s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int x = 1;
	for(int i = 0; i < n; i++){
		char c;
		cin >> a[i];
		cin >> c;
		for(int j = 0; j < a[i]; j++){
			s[x] = c;
			x++;
		}
	}
	int x2 = x;
	for(int i = 1; i <= x; i++){
		s2[i] = s[x2 - 1];
		x2--;
	}
	
	for(int i = 1; i <= x / 2; i++){
		if(s[i] != s2[i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
