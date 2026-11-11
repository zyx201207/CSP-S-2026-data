#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int c(string s){
	int A=s[0]-'0',B=s[1]-'0';
	return A*10+B;
}
int ch(string s){
	int A=s[2]-'A'+1;
	return A;
}
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>a1;
	cin>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	int x=c(a1),y=c(b1);
	if(x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	x=ch(a1);
	y=ch(b1);
	if(x==1||x==2||x==3){
		if(y==1||y==2||y==3){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(x==4||x==5){
		if(y==4||y==5){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	int z=x-y;
	if(z==1||z==-1){
		if(x==3||x==4&&y==3||y==4){
			cout<<0;
			return 0;
		}
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
