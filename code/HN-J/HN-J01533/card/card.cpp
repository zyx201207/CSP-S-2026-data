#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i-1];
	}	
	cout << m << " " << a[0] << " " << n;
	return 0;
}
