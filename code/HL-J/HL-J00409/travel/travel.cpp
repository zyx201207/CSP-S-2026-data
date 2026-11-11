#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	int a1=0,b1=0,c1=0,d1=0;
	if(a==c){
		a1=1;
	}
	else{
		cout<<a1<<b1<<c1<<d1<<endl;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		b1=1;
	}
	else{
		cout<<a1<<b1<<c1<<d1<<endl;
		return 0;
	}
	if(((b[2]>='A'&&b[2]<='C'&&b[2]!=d[2])&&(d[2]>='A'&&d[2]<='C'&&d[2]!=b[2]))||((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))){
		c1=1;
	}
	if((b[2]-1==d[2]||b[2]+1==d[2])||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
		d1=1;
	}
	if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
		d1=0;
	}
	cout<<a1<<b1<<c1<<d1<<endl;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
