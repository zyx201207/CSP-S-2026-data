#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(string.in,"r";stdin);
	freopen(string.out;"w",stdout);
	long long n,sum = 0;
	cin >> n;
	long long a[10005];
	string c[10005];
	for(int i =0;i<=n-1;i++){
		cin >> a[i] >> c[i];
	}
	for (int i=0;i<=n-1;i++){	
		if(c[i] != c[n-1-i]){
			if(i/2==0 && n%i==1){
				sum += 0;
			}else{
				sum += a[n-1-i];
			}
		}else{
			sum += 0;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
