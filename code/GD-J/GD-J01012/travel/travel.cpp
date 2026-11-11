#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b;
	cin>>c>>d>>e;
	cin>>f>>g;
	cin>>h>>i>>j;
	if(a==f&&b==g){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(c==h&&d==i){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((e=='F'&&j=='D')||(e=='D'&&j=='F')){
		cout<<"11";
		return 0;
	}else if((e=='A'&&j=='B')||(e=='B'&&j=='A')||(e=='B'&&j=='C')||(e=='C'&&j=='B')){
		cout<<"11";
		return 0;
	}else if((e=='C'&&j=='D')||(e=='D'&&j=='C')){
		cout<<"00";
		return 0;
	}else{
		cout<<"10";
	}
	return 0;
} 
