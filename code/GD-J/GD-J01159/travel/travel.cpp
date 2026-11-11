#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool a1=0,b1=0,c1=0,d1=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]){
    	a1=1;
    	if(b[0]==d[0]&&b[1]==d[1]){
			b1=1;
			if(((b[2]>='A'&&d[2]>='A')&&(b[2]<='C'&&d[2]<='C'))||((b[2]>'C'&&d[2]>'C')&&(b[2]<='E'&&d[2]<='E'))){
				c1=1;
			}if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A'||d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D')){
	  	  		d1=1;
	   		}
		}
	}cout<<a1<<b1<<c1<<d1;
    return 0;
}