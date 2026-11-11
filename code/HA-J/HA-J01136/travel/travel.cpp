#include <bits\stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1<<" ";
	}
	else{
		cout<<0<<" "<<0<<" "<<0<<" "<<0;
		return 0;
	}
	string h1=s1[0]+s1[1],h2=s2[0]+s2[1]
	if(h1==h2){
		cout<<1<<" ";
	}
	else{
		cout<<0<<" "<<0<<" "<<0;
		break;
	}
	if((char(s1[2])-'A'>=0 && char(s1[2])-'A'<=2) && (char(s2[2])-'A'>=0 && char(s2[2])-'A'<=2)){
		cout<<1<<" ";
	}
	else if((char(s1[2])-'A'>=3 && char(s1[2])-'A'<=4) && (char(s2[2])-'A'>=3 && char(s2[2])-'A'<=4)){
		cout<<1<<" ";
	}
	else{
		cout<<0<<" "<<0;
		return 0;
	}
	if((abs((char(s1[2])-'A')-(char(s2[2])-'A'))==1) && (char(s1[2])!='C' && char(s2[2])!='D') && (char(s1[2])!='D' && char(s2[2])!='C')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
