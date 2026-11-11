#include<bits/stdc++.h>

using namespace std;

int c,t;

long long n,d,a[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		long long x = d;
		
		for(long long i=1;i<=n;i++){ 
			cin >> a[i];
		}
		
		long long sum = 0;
		for(long long i=1;i<n-i-x;i++){
			for(long long j=i+1+x;j<=n;j++){
				if(j-i-x==1){
					sum++;
				}
			}
		}
		cout << sum <<endl;
	}
	return 0;
}
