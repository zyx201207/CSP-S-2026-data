#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
long long n,m,a[maxn],canand,ans,dertawei=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ans = pow(2,20)-1;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(long long k = 20;k >= 1;k--){
		canand=0;
		dertawei = 0;
		for(long long j = pow(2,k)-1;j>=pow(2,k-1);){
			if(j==a[n-dertawei]){
				canand++;
				dertawei++;
			}
			else{
				j--;
			}
		}
		
		if(canand>=m){
			for(long long j = 1;j <= m;j++){
				ans &= a[n-j+1];
			}
		}
		else{
			for(long long j = 1;j <= dertawei;j++){
				a[n-j+1] -= pow(2,k-1);
			}
			sort(a+1,a+1+n);
		}
		
		/*
		for(int i = 1;i <= n;i++){
			cout << a[i] << " ";
		}
		cout << endl;
		*/
		
	}
	cout << ans;
	return 0;
} 
