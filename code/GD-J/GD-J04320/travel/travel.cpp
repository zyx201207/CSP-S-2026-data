#include<iostream>
using namespace std;
string a,b,c,d;
int main(){
	std("travel.in","r",std.in);
	std("travel.out","w",std.out);
	int e;
	e=b%100;
	int f=d%100;
	if(a==c){
		cout<<"1";
		if((b==d+1 || b==d-1) && ((b!='C' && d!='D') || (d!='C' && b!='D'))){
			cout <<"111";
		}
	}
	else{
		cout <<"0000";
	}
	return 0;
}
