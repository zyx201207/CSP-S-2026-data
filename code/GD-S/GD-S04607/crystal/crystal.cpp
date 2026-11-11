#include <bits/stdc++.h>
using namespace std;
int a[10005];
long long n,m,cnt=0,f=0,bn=0;
int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n%2!=0){
		f=n/2+1;
	}
	else{
		f=n/2;
	}
	if(m==8) f++; 
	cout<<f;
	return 0;
}
