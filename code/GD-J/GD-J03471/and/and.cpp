#include<bits/stdc++.h>
using namespace std;

long long const N = 10000000;
int n , m;
long long a[N];
long long b[N];
long long k = 0;

long long ans(long long a , long long b){
	return a & b;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i];
    }
    sort(b + 1 , b + n + 1);
    for(int i = n;i > 0;i--){
    	k++;
    	if(k > m) b[i] = 0;
	} 
	if(m == 2) cout << ans(b[n] , b[n - 1]);
	if(m == 3) cout << ans(ans(b[n] , b[n - 1]) , b[n - 2]) ;
	if(m == 4) cout << ans((ans(b[n] , b[n - 1]) , b[n - 2]) , b[n - 3]); 
	else cout << b[m];
	return 0;
}
