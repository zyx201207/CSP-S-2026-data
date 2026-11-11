#include<bits/stdc++.h>
using namespace std;
int a1, a2, d1, d2, z1, z2;
string c1, c2;
string b1, b2;
bool e1, e2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> b1>> a2 >> b2;
	if(a1 == a2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	c1 = b1[2];
	c2 = b2[2];
	d1 = b1[0];
	d2 = b2[0];
	d1 = d1*10+b1[1];
	d2 = d2*10+b2[1];
	if(d1 == d2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if(c1[0]=='A'||c1[0]=='B'||c1[0]=='C'){
		e1 == 1;
	}
	else{
		cout << 0;
	}
	if(c2[0]=='A'||c2[0]=='B'||c2[0]=='C'){
		e2 == 1;
	}
	else{
		cout << 0;
	}
	if(e1 == e2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	z1 = c1[0]-'A';
	z2 = c2[0]-'A';
	if ((z1==z2&&(d1-d2==1||d2-d1==1))||(d1==d2&&(z1-z2==1||z2-z1==1))){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
} 
