#include<bits/stdc++.h> 
using namespace std;

string a,b,c,d;
int q=0,w=0,e=0;//Cici

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		q=1;
	}
	else{
		cout<<"0";
	}
	if(b[0]==d[0]&&b[1]==d[1]&&q){
		cout<<"1";
		w=1;
	}
	else{
		cout<<"0";
	}
	if((b[3]=='A'&&d[3]=='B'&&w)||(b[3]=='A'&&d[3]=='C'&&w)||(b[3]=='B'&&d[3]=='A'&&w)||(b[3]=='B'&&d[3]=='C'&&w)||(b[3]=='C'&&d[3]=='A'&&w)||(b[3]=='C'&&d[3]=='B'&&w)||(b[3]=='D'&&d[3]=='F'&&w)||(b[3]=='F'&&d[3]=='D'&&w)){
		cout<<"1";
		e=1;
	}else{
		cout<<"0";
	}
	if((b[3]=='A'&&d[3]=='B'&&e)||(b[3]=='B'&&d[3]=='A'&&e)||(b[3]=='B'&&d[3]=='C'&&e)||(b[3]=='C'&&d[3]=='B'&&e)||(b[3]=='D'&&d[3]=='F'&&e)||(b[3]=='F'&&d[3]=='D'&&e)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
