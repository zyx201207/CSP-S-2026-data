#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='B'&&b=='A')||(a=='C'&&b=='A')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='B'&&b=='A')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
} 
