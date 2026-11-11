#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	bool a=0,b=0,c=0,d=0;
	if(c1==c3){
		 a=1;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&a){
		b=1;
	}
	if(b&&(((c2[2]>='A'&&c2[2]<='C')&&(c4[2]>='A'&&c4[2]<='C'))||((c2[2]>='D'&&c2[2]<='F')&&(c4[2]>='D'&&c4[2]<='F')))){
			c=1;
	}
	if(((c2[2]-1==c4[2])||(c2[2]+1==c4[2]))&&c){
			d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}

