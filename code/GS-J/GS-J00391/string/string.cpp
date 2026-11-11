#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long m = 0;
	long long n;
	cin>>n;
	long long a[n+5];
	char b[n+5];
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	} 
	string x,y;
	for(long long i = 1;i <= n;i++){
		for(long long j = 1;j <= a[i];j++){
			x = x + b[i];
		}
	}
	for(long long i = 1;i <= n;i++){
		m = m + a[i];
	}
	for(long long i = m-1;i >= 0;i--){
		y = y + x[i];
	}
	long long s = 0;
	if(x==y){
		cout<<s;
	}else{
		for(long long i = 1;i <= m*n;i++){
			if(x[i] != y[i]){
				s++;
			}
		}
		if(s%2==0){
			cout<<s/2;
		}else{
			cout<<s/2+1;
		}
	}
	return 0;
} 

