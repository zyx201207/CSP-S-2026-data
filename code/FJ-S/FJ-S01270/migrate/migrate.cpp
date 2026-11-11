#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000200]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	for(int sss = 1;sss <= t;sss++){
		cin >> n >> d;
		if(n < 4){
			cout << 0 << "\n";
			break;
		}
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		
	}
	return 0;
} 
