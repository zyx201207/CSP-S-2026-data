#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if( !( (d[2]>'C') ^ (b[2]>'C') ) ){
				if(abs(d[2]-b[2])==1) printf("1111");
				else printf("1110");
			} else printf("1100");
		}else printf("1000");
	}else printf("0000");
	return 0;
} 
