#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505,inf = 0x3f3f3f3f;
ll x[N],c,t,n,d,sum; 
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;sum = 0;
		for(int i = 1 ; i <= n ; i++) cin >> x[i];
		for(int i = 2 ; i <= n ; i++){
			for(int j = 1 ; j < i ; j++){
				if(x[i]-x[j] == d+1&&i-j == 3){
					sum++;
				}
				
			}
		}
		cout << sum << "\n";
	}

	return 0;
} 
