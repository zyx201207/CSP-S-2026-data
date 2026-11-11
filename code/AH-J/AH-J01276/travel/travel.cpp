#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		printf("0000");
		return 0;
	}
	if(b[0]!=d[0]||b[1]!=d[1]){
		printf("1000");
		return 0;
	}
	if((b[2]<='C'&&d[2]>'C')||(b[2]>'C'&&d[2]<='C')){
		printf("1100");
		return 0;
	}
	if(abs(b[2]-d[2])>1){
		printf("1110");
		return 0;
	}
	if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
}
