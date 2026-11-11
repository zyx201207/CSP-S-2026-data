#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans;
	cin >> n >> m;
	long long a[200005],j;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long gg,hh = 1;
	sort(a+1,a+n+1); 	
	for(long long i = 1; i <= n; i++){
		if(i == (n-1)/2+1){
			ans = a[i];
			j = i;
		}
	}	
	
	for(int i = j-1; i >= 1; i--){
		gg = ans-a[i];
		if(gg <= m){
			a[i] = ans;
			hh++;
			m-=gg;
		}
	}
	for(int i = j+1; i <= n; i++){
		if(a[i] == ans){
			hh++;
		}else{
			break;
		}
	}
	cout << hh;
	return 0;
}
