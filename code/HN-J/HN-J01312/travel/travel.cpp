#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 1e7 + 5 ;
string A , B , a , b ;
signed main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	cin >> a >> A >> b >> B ;
	if(a == b) cout << 1 ;
	else
	{
		cout << 0 << 0 << 0 << 0 ;
		return 0 ;
	}
	string aa = A.substr(0 , 2) ;
	string bb = B.substr(0 , 2) ;
	if(aa == bb) cout << 1 ;
	else
	{
		cout << "000" ;
		return 0 ;
	}
	if(A[2] == 'A' && B[2] == 'B') cout << 1 << 1 ;
	if(A[2] == 'A' && B[2] == 'C') cout << 1 << 0 ;
	if(A[2] == 'A' && B[2] == 'D') cout << 0 << 0 ;
	if(A[2] == 'A' && B[2] == 'F') cout << 0 << 0 ;
	if(A[2] == 'B' && B[2] == 'A') cout << 1 << 1 ;
	if(A[2] == 'B' && B[2] == 'C') cout << 1 << 1 ;
	if(A[2] == 'B' && B[2] == 'D') cout << 0 << 0 ;
	if(A[2] == 'B' && B[2] == 'F') cout << 0 << 0 ;
	if(A[2] == 'C' && B[2] == 'A') cout << 1 << 0 ;
	if(A[2] == 'C' && B[2] == 'B') cout << 1 << 1 ;
	if(A[2] == 'C' && B[2] == 'D') cout << 0 << 0 ;
	if(A[2] == 'C' && B[2] == 'F') cout << 0 << 0 ;
	if(A[2] == 'D' && B[2] == 'A') cout << 0 << 0 ;
	if(A[2] == 'D' && B[2] == 'B') cout << 0 << 0 ;
	if(A[2] == 'D' && B[2] == 'C') cout << 0 << 0 ;
	if(A[2] == 'D' && B[2] == 'F') cout << 1 << 1 ;
	if(A[2] == 'F' && B[2] == 'A') cout << 0 << 0 ;
	if(A[2] == 'F' && B[2] == 'B') cout << 0 << 0 ;
	if(A[2] == 'F' && B[2] == 'C') cout << 0 << 0 ;
	if(A[2] == 'F' && B[2] == 'D') cout << 1 << 1 ;
	return 0 ;
}

