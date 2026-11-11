#include "bits/stdc++.h" 
using namespace std; 

long long a[2000005], n, c, t, d, dd;

int main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.in","r",stdin);
	
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin>>a[i];
		dd=a[2]-a[1];
		if(d*3<a[4]-a[1] || d*3>=a[5]-a[1]) cout<<"0\n";
		else cout<<n-3<<"\n";
	}
	return 0;
}
