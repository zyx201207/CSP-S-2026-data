#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	a=s1[2];
	b=s2[2];
	bool f=true;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			f=false;
			break;
		}
	}
	if(f){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
		cout<<1;
	}else if((a=='F'||a=='D')&&(b=='F'||b=='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&(b=='A'||b=='C')){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='F'){
		cout<<1;
	}else if(a=='F'&&b=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
