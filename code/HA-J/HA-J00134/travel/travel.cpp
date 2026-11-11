#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int aa,bb,cc,dd;
	if(a==c){
		aa=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			bb=1;
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')){
				cc=1;
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
					dd=1;
				}
				else{
					dd=0;
				}
			}
			else{
				cc=0;
				dd=0;
			}
		}
		else{
			bb=0;
			cc=0;
			dd=0;
		}
	}
	else{
		aa=0;
		bb=0;
		cc=0;
		dd=0;
	}
	cout<<aa<<bb<<cc<<dd;
	return 0;
}
