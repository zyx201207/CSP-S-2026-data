#include<bits/stdc++.h>
using namespace std;
long long a[500086];
long long sum[500086];
long long n,m;
bool ck(int x){
	for(int i = 1; i <= n ;i++){
		if(i > 2){
		    if(a[i]-a[i-1] != a[i-1]-a[1-2]){
		    	return false;
			} 
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n ;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if(ck(1)){
		long long p = a[2]-a[1];
	    long long sum = 1;
	    for(long long i = 1; i <= n; i++){
	    	m -= p * i;
	    	sum++;
	    	if(m < 0){
	    		sum--;
	    		break;
	    	}
    	}
    	if(sum > n){
    		cout << n;
		}else{
			cout << sum;
		}
	}else {
		long long c = 0;
	    for(int i = 1; i <= n ;i++){
	    	if(i > 1){
	    		sum[c++] = a[i] - a[i-1];
	    	}
    	}
    	c--;
        long long p = 1;
    	for(long long i = 0; i < c; i++){
	    	m -= (i+1) * sum[i];
	    	p++;
	    	if(m < 0){
	        	p--;
		    	break;
	    	}
	    }
	    cout <<p;
	}
	return 0;
}
