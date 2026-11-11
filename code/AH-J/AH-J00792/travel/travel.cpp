#include<bits/stdc++.h>
using namespace std;
char x[5],y[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	cin >> a >> x >> b >> y;
	bool pd=true;
	if(a==b){
		cout << '1';
	}else{
		cout << '0';
		pd=false;
	}
	if(x[0]==y[0]&&pd){
		if(x[1]==y[1]){
			cout << '1';
		}else{
			cout << '0';
			pd=false;
		}
	}else{
		cout << '0';
		pd=false;
	}
	char n=x[2],m=y[2];
	if(!pd){
		cout << '0';
	}else if(n>='A'&&n<='C'&&m>='A'&&m<='C'){
		cout << '1';
	}else if(n>='D'&&n<='F'&&m>='D'&&m<='F'){
		cout << '1';
	}else{
		cout << '0';
		pd=false;
	}
	if(!pd){
		cout << '0';
	}else if(n=='A'&&m=='B'){
		cout << '1';
	}else if(n=='B'&&m=='A'||n=='B'&&m=='C'){
		cout << '1';
	}else if(n=='C'&&m=='B'){
		cout << '1';
	}else if(n=='D'&&m=='F'){
		cout << '1';
	}else if(n=='F'&&m=='D'){
		cout << '1';
	}else{
		cout << '0';
	}
	return 0;
}
