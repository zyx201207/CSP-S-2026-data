#include<bits/stdc++.h>
using namespace std;

int n, ans;
int s[100010];
int sum;
string b, c;
char a[100010];

int main(){
	
	freopen( "string1.in", "r", stdin );
	freopen( "string1.out", "w", stdout );
	
	cin >> n;
	for( int i = 1; i <= n; i++ ){
		cin >> s[i];
		cin >> a[i];
		sum += s[i];
		for( int j = 0; j < s[i]; j++ ){
			b += a[i];
		}
	}
	
	for( int i = 0; i < sum / 2; i++ ){
		c[i] = b[i];
	}
	
	for( int i = sum / 2; i < sum; i++ ){
		if( sum % 2 && i == sum / 2 ){
			continue;
		}if( b[i] != c[i] ){
			ans++;
		}
	}
	
	cout << ans;
	
	
	return 0;
} 
