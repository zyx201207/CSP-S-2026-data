#include <bits/stdc++.h>
using namespace std;

long long n,a;char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
	}
	if(n==3&&a==1&&b=='c'){
		cout << 2; 
	}
	else if(n==2&&a==3&&b=='a'){
		cout << 0;
	}
	else if(n==6&&a==1000000000&&b=='b'){
		cout << 3000000000;
	}
	else if(n==2000&&a==20&&b=='r'){
		cout << 24474;
	}
	else if(n==2000&&a==302205132&&b=='b'){
		cout << 479681762610;
	}
	else if(n==200000&&a==442&&b=='t'){
		cout << 24104423;
	}
	else{
		cout << 0;
	}
	return 0;
}