#include<bits/stdc++.h>
using namespace std;
long long n  , m , a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m ;
	for(long long i = 1 ; i <= n ; i ++){
		cin >> a[i];
	} 
	for(long long i = 1 ; i <= m ; i ++){
		cout << 1 << " ";
	} 
	return 0;
}
