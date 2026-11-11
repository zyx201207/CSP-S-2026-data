#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	int  x,n;
	string y,m,a="";
	cin >>x>>y>>n>>m;
	if(x==n){
		a+="1";
		if((y[0]+y[1])==(m[0]+m[1])){
		    a+="1";
		    if(y[2]>'C' && m[2]<'D'){
		    	a+="00";
			}
			else{
				a+="1";
				if((y[2]=='A'&& m[2]=='C')||(y[2]=='C'&&m[2]=='A')){
					a+="0";
				}
				else{
					a+="1";
				}
			}
	    }
	    else{
	    	a+="000";
		}
	}
	else{
		a+="0000";
	}
	cout <<a;
	return 0;
}
