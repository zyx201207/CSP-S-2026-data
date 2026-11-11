#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string R,r,X,x;
	cin>>R>>r>>X>>x;
	bool flag=false;
	char a='0',b='0',c='0',d='0';
	if(R==X){
		a='1';
		flag=true;
	}
	else{
		flag=false;
	}
	if(flag&&r[0]==x[0]&&r[1]==x[1]){
		b='1';
		flag=true;
	}
	else{
		flag=false;
	}
	if(flag&&r[2]>='A'&&r[2]<='C'&&x[2]>='A'&&x[2]<='C'){
		c='1';
		flag=true;
	}
	else if(flag&&r[2]>='D'&&r[2]<='F'&&x[2]>='D'&&x[2]<='F'){
		c='1';
		flag=true;
	}
	else{
		flag=false;
	}
	if(flag&&((r[2]=='D'&&x[2]=='F')||(r[2]=='F'&&x[2]=='D')))d='1';
	else if(flag&&((r[2]=='D'&&x[2]=='C')||(r[2]=='C'&&x[2]=='D')))d='0';
	else if(flag&&abs(int(r[2]-x[2]))==1)d='1';
	cout<<a<<b<<c<<d;
	return 0;
}
