#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else {
		cout<<0;
	}
	string a1="",b1="";
	char a,b;
	for(int i=0;i<=1;i++){
		a1+=s1[i];
		b1+=s2[i];
	}
	a=s1[2],b=s2[2];
	if(a1==b1){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if((a=='A'&&(b=='B'||b=='C'))||(a=='B'&&(b=='A'||b=='C'))||(a=='C'&&(b=='B'||b=='A'))){
		cout<<1;
	}
	else if((a=='D'&&b=='F')||(a=='F'&&b=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((a=='A'&&b=='B')||(a=='B'&&(b=='A'||b=='C'))||(a=='C'&&b=='B')){
		cout<<1;
	}
	else if((a=='D'&&b=='F')||(a=='F'&&b=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
