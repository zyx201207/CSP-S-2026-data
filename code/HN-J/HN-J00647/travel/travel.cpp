#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	char x=s1[0];
	char n=s1[1];
	char y=s2[0];
	char m=s2[1];
	if(x==y&&n==m){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char z=s1[2];
	char r=s2[2];
	if(z=='A'){
		if(r=='B'){
			cout<<"11";
		}else if(r=='C'){
			cout<<"10";
		}else{
			cout<<"00";
		}
	}
	if(z=='B'){
		if(r=='A'||r=='C'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
	if(z=='C'){
		if(r=='B'){
			cout<<"11";
		}else if(r=='A'){
			cout<<"10";
		}else{
			cout<<"00";
		}
	}
	if(z=='D'){
		if(r=='F'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
	if(z=='F'){
		if(r=='D'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
	return 0;
}
