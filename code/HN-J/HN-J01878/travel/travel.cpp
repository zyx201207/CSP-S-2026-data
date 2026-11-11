#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e,f,g;
	cin>>a>>b>>c>>d;
	f=b[0]+b[1];
	g=d[0]+d[1];
	if(a==c) {
		e=e+'1';
		if(f==g) e=e+'1';
		else e=e+"000";
		if(f==g) {
			if(b[2]>='D'&&d[2]>='D') {
				e=e+'1';
				char z1=b[2],z2=d[2]; 
		        if(z1==z2+1||z1==z2-1) e=e+'1';
		        else e=e+'0';
			}
			else if(b[2]<='C'&&d[2]<='C') {
				e=e+'1';
				char z1=b[2],z2=d[2]; 
		        if(z1==z2+1||z1==z2-1) e=e+'1';
		        else e=e+'0';
			}
			else e=e+"00";
		}
	}
	else e=e+"0000";
	cout<<e;
	return 0;
} 
