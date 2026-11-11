#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	vector<long long> a;
	long long c,t;
	cin >> c>>t; 
	long long n,d;
	for (int u=0;u<t;u++){
		cin >> n >> d;
		a.resize(n);
		for (int i=0;i<n;i++){
			cin >> a[i];
		}
		if (d==1){
			cout << 0;
		}
		else if (d>a[n-1]-a[0]){
			cout << n;
		}
		else if (d<a[n-1]-a[0]){
			cout << 1;
		}else{
			cout << 0;
		}
		cout << endl;
		
	}
	
	return 0;
} 
