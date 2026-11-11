#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
#define int ll
const int N = 2e5 + 10;
//-static
int n;
int a[N];
char ch[N];

signed main(){
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout );
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int num = 0;
	for( int i = 1 ; i <= n ; i++ ) cin >> a[i] >> ch[i];
	for( int i = 1 , j = n ; i <= j ; i++ , j-- ){
		if( ch[i] != ch[j] ){
			if( a[i] >= a[j] ){
				a[i] -= a[j];
				num += a[j];
				a[j] = 0;
				i--;
			}else{
				a[j] -=	a[i];
				num += a[i];
				a[i] = 0;
				j++;
			}
		}
			
	}
	cout << num;
	return 0;
}
