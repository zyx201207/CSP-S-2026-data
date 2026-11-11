#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int nn = 2e5 + 10;
int a, b, n, ant, maxx;
string st;

int main(){
	freopen( "string.in", "r", stdin );
	freopen( "string.out", "w", stdout );
	cin >> n;
	char c;
	for( int i = 1, a; i <= n; i++ ){
		cin >> a >> c;
		for( int j = 1; j <= a; j++ ){
			st += c;
		}
	}
	for( int i = 0, j = st.size() - 1; j >= 0; i++, j-- ){
		if( st[i] != st[j] ){
			ant++;
		}
	}
	cout << ant / 2 << endl;
	return 0;
}
