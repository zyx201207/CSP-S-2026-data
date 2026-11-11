#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
bool b=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
	}
	else{
		cout<<"0";
		b=1;
	}
	string r2,x2,wr,wx,rr,xx;
	r2=sr[0];
	x2=sx[0];
	r2+=sr[1];
	x2+=sx[1];
	rr=sr[2];
	xx=sx[2];
	if(r2==x2&&!b){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if((rr=="A"||rr=="B"||rr=="C")&&(xx=="A"||xx=="B"||xx=="C")&&!b){
		cout<<"1";
	}
	else if((rr=="D"||rr=="F")&&(xx=="D"||xx=="F")&&!b){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if((rr=="A"&&xx=="B")||(rr=="B"&&xx=="C")||(xx=="A"&&rr=="B")||(xx=="B"&&rr=="C")&&!b){
		cout<<"1";
	}
	else if((rr=="D"&&xx=="F")||(rr=="F"&&xx=="D")&&!b){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
