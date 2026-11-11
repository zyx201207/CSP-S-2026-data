#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,e="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		e+='1';
		if(b[0]==d[0] && b[1]==d[1]){
			e+='1';
			if(b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C' || b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F'){
				e+='1';
				if(abs(b[2]-d[2])==1 || b[2]=='D' && d[2]=='F' || b[2]=='F' && d[2]=='D'){
					e+='1';
				}
				else{
					e+='0';
				}
			}
			else{
				e+="00";
			}
		}
		else{
			e+="000";
		}
	}
	else{
		e+="0000";
	}
	cout<<e;
	return 0;
} 
