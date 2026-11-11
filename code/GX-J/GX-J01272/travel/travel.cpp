#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,n;
	int b,m;
	int f=0;
	cin >> a >> n >> b >> m;
	if(a == b){
		cout << '1';
	}
	if(n/100 == m/100){
		cout << '1';
	}
	if(n/10 == m/10){
		cout << '1';
	}
	if(n%10 == 'A' and n%10 == 'B'){
		f = 1;
	}
	if(n%10 == 'A' and n%10 == 'A'){
		f = 1;
	}
	if(n%10 == 'A' and n%10 == 'C'){
		f = 1;
	}
	if(n%10 == 'B' and n%10 == 'A'){
		f = 1;
	}
	if(n%10 == 'C' and n%10 == 'A'){
		f = 1;
	}
	if(n%10 == 'D' and n%10 == 'F'){
		f = 1;
	}	
	if(n%10 == 'F' and n%10 == 'D'){
		f = 1;
	}	
	if(f==1){
		cout << '1';
	}
    return 0;
    }
