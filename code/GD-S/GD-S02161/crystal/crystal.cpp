#include<bits/stdc++.h>
using namespace std;
long long n,m,f = 1,f1 = 1,ans,mmax;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i){
			f = 0; 
		}
		if(i >=3&&a[i]-a[i-1] != a[i-1] - a[i-2]){
			f1 = 0;
		}
	} 
	if(f){
		long long c = 1;
	    while(ans <= m){
		   ans += c;
		   if(ans > m){
		   	cout << c;
		   	break;
		   }
		   c++;
	    }
	    return 0;
	}else if(f1){
		long long sum = a[2] - a[1];
		m /= sum;
		long long k = 1;
	    while(ans <= m){
		   ans += k;
		   if(ans > m){
		   	cout << k;
		   	break;
		   }
		   k++;
	    }
	    return 0;
	}else{
		sort(a,a+n); 
		long long b[100000],sum,js = 1,d;
		for(int i = 2;i <= n;i++){
			b[i]  = a[i] - a[1]; 
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(b[j] == b[j-1]){
				   js++;
	               continue;
			   }
	           d = b[j] - b[i];
	           if(sum + d <=m){
	           	  js++;
	           	  sum += d;
			   }else{
			   	mmax = max(js,mmax);
			   	js = 0;
			   	sum = 0;
			   	break;
			   }
			}
		}
		cout<< mmax;
	} 
	return 0;
}
