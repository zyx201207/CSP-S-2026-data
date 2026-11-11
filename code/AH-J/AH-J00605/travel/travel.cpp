#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e,f,g,h;
	int n=0,m=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		n=1;
	}
	else{
		cout<<0;
	}
	e=b.substr(0,2);
	f=d.substr(0,2);
	if(e==f){
		cout<<1;
		m=1;
	}
	else{
		cout<<0;
	}
	g=b.substr(2,1);
	h=d.substr(2,1);
	if(((g<="C"&&h<="C")||(g>="D"&&h>="D"))&&n==1&&m==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(((g=="A"&&h=="B")||(g=="B"&&h=="A")||(g=="B"&&h=="C")||(g=="C"&&h=="B")||(g=="D"&&h=="F")||(g=="F"&&h=="D"))&&n==1&&m==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
