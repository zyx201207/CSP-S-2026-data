#include<bits/stdc++.h>
using namespace std;
#define int long long

int n , m , a[201010] , c[201010] , lc;
int b[201010] , s[201010];

signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	for (int i = 1; i <= n; i++){
		memset(c , 0 , sizeof(c));
		memset(b , 0 , sizeof(b));
		lc = 0;
		for (int j = i; j <= n; j++){
			if (b[a[j]] == 0){
				c[++lc] = a[j];
				b[a[j]] = lc;
			}else
				lc = b[a[j]];
		}
		bool bb[201010]; memset(bb , 0 , sizeof(bb));
		for (int j = 1; j <= lc; j++)
			if (bb[c[j]] == 0)
				s[c[j]]++ , bb[c[j]] = 1;
//		for (int j = 1; j <= n; j++)
//			cout << c[j] << " ";
//		cout << endl;
	}
	for (int i = 1; i <= m; i++)
		cout << s[i] << " ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
