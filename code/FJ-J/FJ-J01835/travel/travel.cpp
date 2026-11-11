#include<bits/stdc++.h>
using namespace std;

string x,y;
int q,p;//³µÏáºÅ
int r,d;//×ùÎ»ºÅ
char a,b;//±àºÅ 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>x>>p>>y;
	if(q!=p){
		cout<<"0000";
		return 0;
	}
	r=(x[0]-'0')*10+(x[1]-'0'),d=(y[0]-'0')*10+(y[1]-'0');
	if(r!=d){
		cout<<"1000";
		return 0;
	}
	a=x[2],b=y[2];
	if((a>='A'&&a<='C'&&b>='D')||(b>='A'&&b<='C'&&a>='D')){
		cout<<"1100";
		return 0;
	}
	if(a+1==b){
		cout<<"1111";
	}
	else if(a-1==b){
		cout<<"1111";
	}
	else cout<<"1110";
	return 0;
}
