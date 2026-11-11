#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long a[200006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >>d;
		for(int i = 1 ; i <= n ; i ++){
			cin >>a[i]; 
		}
		if(n <= 2){
			cout<<0<<endl;
		}
		else{
			long long xxx= a[2] - a[1];
			if(xxx <2*d){
			cout<<0<<endl;
		}
		else cout<<n-(d/xxx)<<endl;
		}

	}
	return 0; 
} 
