#include<bits/stdc++.h>
using namespace std; 
char b,d;
int x,y;
int a,c;
int pd(char a,char b){
	if(a=='A'||a=='C'||a=='B'){
		if(b=='A'||b=='C'||b=='B'){
			return 1;
		}
	}
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			return 1;
		}
	}
	return 0;
}
int xl(char a,char b){
	if(a=='A'&&b=='B'){
		return 1;
	}
	if(b=='A'&&a=='B'){
		return 1;
	}
	if(b=='C'&&a=='B'){
		return 1;
	}
	if(a=='C'&&b=='B'){
		return 1;
	}
	if(a=='D'&&b=='F'){
		return 1;
	}
	if(b=='D'&&a=='F'){
		return 1;
	}
	return 0;
}
int main(){
	//Trick||Treat!
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>c>>y>>d;
	if(a==c){
		cout<<"1";
		if(x==y){
			cout<<"1";
			if(pd(b,d)==1){
				cout<<"1";
				if(xl(b,d)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	} 
	return 0;
}
