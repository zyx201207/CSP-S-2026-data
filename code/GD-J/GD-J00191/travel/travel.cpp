#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char x,y;
int check(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b==d){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(check(x)==check(y)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(check(x)==1){
		if(abs(x-y)==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"1";
	}
	return 0;
}
