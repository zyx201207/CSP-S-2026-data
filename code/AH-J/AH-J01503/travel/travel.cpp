#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool f1,f2,f3,f4;
	cin>>a>>b>>c>>d;
	if(a==c) f1=1;
	else f1=0;
	int e,f,g,h;
	char g2,h2;
	e=(b[0]-48)*10+b[1]-48,f=(d[0]-48)*10+d[1]-48;
	g2=b[2],h2=d[2];
	g=int(g2),h=int(h2);
	if(e==f&&f1==1){
		f2=1;
		if((g<=67&&h<=67)||(g>67&&g<=69&&h>67&&h<=69)){
			f3=1;
		}else{
			f3=0;
		}
	}else{
		f2=0,f3=0;
	}
	if(f1==1&&f2==1&&f3==1&&abs(g-h)==1){
		f4=1;
	}else{
		f4=0;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
