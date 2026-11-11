#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d; 
long long x[2000010]; 


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	
	while(t--){
		for(int i = 0;i<2000010;i++) x[i] = 0; 
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		} 
		int ans = 0; 
		for(int i=1;i<=n;i++){
			int cnt = 0, flag = 0; 
			for(int j=i+2;j<=n;j++){
				for(int k=i+1;k<=j;k++){
					if(abs(x[j] - x[k]) <= d && abs(x[k] - x[i]) <= d){
						cnt++;
						if(cnt > 2){
							flag = 1;
							break;
						} 
					}
				}
				if(flag) break; 
			}
			ans++;
		}
		cout << ans << endl;
		 
	} 
	
	
	
	
	
	return 0;
}
