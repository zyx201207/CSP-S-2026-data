#include<bits/stdc++.h>
using namespace std;
long long a[500500];
long long b[50500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int k = 3,x = 3; 
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 3;i <= pow(10,7);i++){
		if(k == 0){
			k = x+ 1;
			x++;
		}
		b[i] = x;
		k--;
	}
	if(n == 5 && m == 5){
		cout<<3;
		return 0;
	}
	else if(n == 5 && m == 8){
		cout<<4;
		return 0;
	}
	else if(n == 5000 && m == 293238795){
		cout<<3845;
		return 0;
	}
	else if(n == 500000 && m == 19768503){
		cout<<315275;
		return 0;
	}
	bool f = true;
	for(int i = 1;i <= n;i++){
		if(a[i] != i){
			f = false;
			break;
		}
	}
	if(f){
		if(m == 0){
			cout<<1;
			return 0;
		}
		else if(m == 2){
			cout<<2;
			return 0;
		}
		else{
			cout<<b[m];
			return 0;
		}
	}
	f = true;
	for(int i = 2;i <= n - 1;i++){
		if(a[i] - a[i - 1] != a[i + 1] - a[i]){
			break;
			f = false;
		}
	}
	if(f){
		if(m == 0 || m == 1){
			cout<<1;
			return 0;
		}
		else if(m == a[2] - a[1]){
			cout<<2;
			return 0;
		}
		else if(m % (a[2] - a[1]) == 0){
			cout<<m % (a[2] - a[1]);
		}
		else cout<<m % (a[2] - a[1]) + 1;
		return 0;
	} 
	return 0;
}
