#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct sss{
	int a;
	char b;
}arr[200005];
int main(){
	freopen ( "string.in" , "r" , stdin );
	freopen ( "string.out" , "w" , stdout );
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> arr[i].a >> arr[i].b;
	}
	int L = 1,R = n;
	while ( L <= R ){
		int A = arr[L].a,B = arr[R].a;
		if ( arr[L].b != arr[R].b ){
			if ( A > B ){
				arr[L].a -= B;
				ans += arr[R].a;
				R--;
			}else if ( A < B ){
				arr[R].a -= A;
				ans += arr[L].a;
				L++;
			}else{
				ans += arr[L].a;
				L++,R--;
			}
		}else{
			if ( A > B ){
				arr[L].a -= B;
				R--;
			}else if ( A < B ){
				arr[R].a -= A;
				L++;
			}else{
				L++,R--;
			}			
		}
	}
	cout << ans;
	return 0;
}
