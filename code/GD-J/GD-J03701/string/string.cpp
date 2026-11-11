#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,m=0,k=1,l=0,c;
	cin >> n;
	long long a[n];
	long long d1=0,sum=0,d2=0;
	string b;
	for(long long i = 0;i < n;i++){
		cin >> a[i] >> b[i];
		m += a[i];
	}
	m = m / 2;
	for(int i = 0;i < k;i++){
		if(a[i] < m){
			k++;
			m -= a[i];
		}else{
			d1 = a[i] - m;
			l = i;
			k--;
		}
	}
	if(d1 > m){
		d2 = d1 - m;
		a[l] = d2;
	}else{
		d2 = m - d1;
		a[l] = d2;
		l += 1;
	}
	for(int i = 0;i < l;i++){
		sum += a[i];
	}
	cout << sum;
	
	 
	
	return 0;
}

