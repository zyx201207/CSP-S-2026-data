#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,x[2000005],m,a,b;
	cin >> c >> t;
	for(int i = 0 ; i < t ; i++){
		cin >> n >> d;
		for(int j = 0 ; j < n ; j++){
			cin >> x[j];
		}
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				for(int l = j ; l <= k ; l++){
					if(x[k] - x[l] <= d){
						a++;
					}
					else if(x[l] - x[j] <= d && x[k] - x[l] <= d && a == 0){
						b++;
					}
				}
			}
		}
		if(a == 0){
			cout << b;
		}else{
			cout << a;
		}
	}
	freclose(stdin);
	freclose(stdout);
	return 0;
}
