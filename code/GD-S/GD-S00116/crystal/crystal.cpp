#include<bits/stdc++.h>
using namespace std;
long long n , m , sum = 17 , sum_max = 0;
long long a[500010];
int main (){
	cin >> n >> m;
	for(long long i = 1; i<= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(long long i = 2; i<= n ; i++){
		for(long long j = i-1 ;j >= 1; j--){
			sum += a[i] - a[j];
		}
		if(sum <= m){
			long long m1 = m-sum;
			if(!m1%i){
				sum_max = max(sum_max,i);
			}else{
				sum_max = max(sum_max,max(m1%i,i-m1%i));
			}
		}else{
			long long m1 = m,m2 = 0;
			for(long long j = i-1; j >= 1; j--){
				m1 -= a[i]-a[j];
				m2++;
				if(m1 == 0){
					sum_max = max(sum_max,m2);
					break;
				}
				if(m1 < 0){
					sum_max = max(sum_max,m2-1);
					break;
				}
			}
		}
		sum = 0;
	}
	cout << sum_max;
	return 0;
} 
