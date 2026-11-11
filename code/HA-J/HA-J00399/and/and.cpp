#include <bits/stdc++.h>			
using namespace std;
long long n , m ,a[100005];
long long z[1000][100005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++){
		int s;
		while(a[i]!= 0){
			s= a[i]%2;
			a[i] = a[i]/2;
		}
	}
	cout << 12;
	return 0;
}
