#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rn,rm,xn,xm;
	cin>>rn>>rm>>xn>>xm;
	if(rn==xn){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(rm[0]==xm[0] && rm[1]==xm[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(rm[2]>='A' && rm[2]<='C' && xm[2]>='A' && xm[2]<='C'){
		cout<<1;
		if(abs(rm[2]-xm[2])==1){
			cout<<1;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(rm[2]>='D' && rm[2]<='F' && xm[2]>='D' && xm[2]<='F'){
		cout<<1<<1;
		return 0;
	}
	else{
		cout<<0<<0;
		return 0;
	}
}
