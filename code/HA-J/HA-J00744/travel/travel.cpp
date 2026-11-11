#include<bits/stdc++.h>
#include<string>
using namespace std;
string cr,sr,cx,sx,r,x;
int ar,br,ax,bx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	ar=int(cr[0]-48)*10+int(cr[1]-48);
	ax=int(cx[0]-48)*10+int(cx[1]-48);
	r=sr[2];
	x=sx[2];
	br=int(sr[0]-48)*10+int(sr[1]-48);
	bx=int(sx[0]-48)*10+int(sx[1]-48);
	if(ar==ax){
		cout<<"1";
		if(br==bx){
			cout<<"1";
			if((r=="A"&&x=="B")||(r=="B"&&x=="A")||(r=="A"&&x=="C")||(r=="C"&&x=="A")||(r=="C"&&x=="B")||(r=="B"&&x=="C")||(r=="D"&&x=="F")||(r=="F"&&x=="D")){
				cout<<"1";
				if((r=="A"&&x=="B")||(r=="B"&&x=="A")||(r=="C"&&x=="B")||(r=="B"&&x=="C")||(r=="D"&&x=="F")||(r=="F"&&x=="D")){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

