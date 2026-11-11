#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;	
	}
	int p=0;
	for(int i=0;i<2;i++){
		p*=10;
		p+=(b[i]-'0');
	}
	int q=0;
	for(int i=0;i<2;i++){
		q*=10;
		q+=(d[i]-'0');
	}
	if(p==q){
		cout << 1;
	}
	else{
		cout << "000";
		return 0; 
	} 
	bool t=b[2]>='A'&&b[2]<='C';
	bool o=b[2]=='D'||b[2]=='F';
	bool j=d[2]>='A'&&d[2]<='C';
	bool k=d[2]=='D'||d[2]=='F';
	if((t&&j)||(o&&k)){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	char ch1=b[2],ch2=d[2];
	if(ch1>ch2){
		ch1=d[2];
		ch2=b[2];
	}
	if((ch1=='A'&&ch2=='B')||(ch1=='B'&&ch2=='C')||(ch1=='D'&&ch2=='F')){
		cout << 1;
	}
	else cout << 0;
	return 0;
} 
