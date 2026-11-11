#include <bits/stdc++.h>
using namespace std;
long long a[100000000005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s=a[i];
	} 
	cout << (n-2)||(n-1);
	
	return 0;
}
