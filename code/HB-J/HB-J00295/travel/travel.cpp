#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool i,j,k,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(!(a==c)){
		cout<<"0000";
		return 0;
	}
	if(!((b[0]==d[0])&&(b[1]==d[1]))){
		//cout<<(b[0]==d[0])<<' '<<(b[1]==d[0]);
		cout<<"1000";
		return 0;
	}
	
	if(b[2]>='A'&&b[2]<='C'){i=1;}
	if(d[2]>='A'&&d[2]<='C'){j=1;}
	if(b[2]>='D'&&b[2]<='F'){k=1;}
	if(d[2]>='D'&&d[2]<='F'){l=1;}
	if((i&&l)||(j&&k)){
		cout<<"1100";
		return 0;
	}
	if(i&&j){
		cout<<"111";
		if((b[2]=='A'&&d[2]=='C')||(d[2]=='A'&&b[2]=='C')){
			cout<<'0';
		}else{
			cout<<'1';
		}
	}
	if(k&&l){
		cout<<"1111";
	}
	return 0;
}
