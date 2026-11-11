#include<iostream>
using namespace std;
int k4(int a,int b){
	return a & b;
}
bool k2(int n){
	while(n > 0){
		if(n == 1) return 1;
		if(n % 2 == 1) return 0;
		n /= 2;
	}
}
int k1(int n){
	n++;
	while(!k2(n)){
		n++;
	}
	return n * 2 - 1;
}

int k(int a,int b){
	return a ^ b;
}
int k3(int a,int b){
	return k(k1(k(a,b)),k(a,b));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005] = {0},s[200005] = {0},ma = 0;
	cin>>n>>m;
	cin>>a[1];
	s[1] = a[1];
	for(int i = 2;i <= n;i++){
		cin>>a[i];
		s[i] = k4(s[i - 1],a[i]);
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ma = max(ma,k4(a[i],a[j]));
			}
		}
	}
	else if(m == n) ma = s[n];
	else{
		for(int i = 1;i <= n;i++){
			ma = max(ma,k3(s[i + m],s[i]));
		}
	}
	
	cout<<ma;
	return 0;
} 
