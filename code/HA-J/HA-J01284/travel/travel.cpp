#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int t1,t2,t3,t4;
	
	t1=(b[0]-'0')*10;t1+=b[1]-'0';
	t2=(d[0]-'0')*10;t2+=d[1]-'0';
	
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') t3=1;
	if(b[2]=='D'||b[2]=='F') t3=2;
	
	if(d[2]=='A'||d[2]=='B'||d[2]=='C') t4=1;
	if(d[2]=='D'||d[2]=='F') t4=2;
	//cout<<t1<<' '<<t2<<'\n';
	if(a!=c){cout<<"0000";return 0;}
	else if(t1!=t2){cout<<"1000";return 0;}
	else if(t3!=t4){cout<<"1100";return 0;}
	else{
		if(b[2]=='A'&&d[2]=='C'){cout<<"1110";return 0;}
		else if(b[2]=='C'&&d[2]=='A'){cout<<"1110";return 0;}
		else{cout<<"1111";return 0;}
	}
	return 0; 
} 
