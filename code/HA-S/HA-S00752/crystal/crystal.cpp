#include<bits/stdc++.h>
using namespace std;


int n;
long long m;
long long a[500005];
long long f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	bool s_A = 1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(s_A==1)if(a[i] != i)s_A = 0;
	}
	
//特殊性质A： 
	if(s_A==1){
		long long ans = floor((sqrt(1+8*m)-1)/2) +1;
		if(ans > n){
			cout << n;
			return 0;
		}else{
			cout << ans;
			return 0;
		}
	}
	sort(a+1,a+n);

//	for(int i=1;i<=n;i++){
//		cout <<  a[i] << ' ';
//	
//	}

//特殊性质B：
	long long s = a[3]-a[2];

	bool s_B=1;
	for(int i=2;i<=min(15,n);i++){

		if((a[i]-a[i-1])!=s)s_B=0;
	}
	if(s_B==1){
		long long ans = floor((sqrt(1+8*m/s)-1)/2) +1;
		if(ans > n){
			cout << n;
			return 0;
		}else{
			cout << ans;
			return 0;
		}
	}

	for(int i=1;i<=n;i++){
		f[i] = 	a[i]+a[i-1];
	}

	long long ans = 1;
	for(int i=1;i<=n;i++){
		for(long long k=1;i-k-1>=0;k++){
			long long temp = k*a[i]+f[i-k-1]-f[i-1];
		if(temp<=m){
			ans = max(ans,temp);
		}	
	}
	}
	cout << ans;
	
	return 0;
} 
