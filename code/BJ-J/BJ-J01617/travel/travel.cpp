#include<bits/stdc++.h>
#define ll long long
using namespace std;
string f(char ch1,char ch2){
	string s="";
	s+=ch1;
	s+=ch2;
	return s;
}
ll g(char ch){
	if(ch=='A'||ch=='B'||ch=='C'){
		return 1;
	}
	return 2;
}
bool h(char ch1,char ch2){
	if(ch1=='A'&&ch2=='B'){
		return 1;
	}
	if(ch1=='B'&&ch2=='A'){
		return 1;
	}
	if(ch1=='B'&&ch2=='C'){
		return 1;
	}
	if(ch1=='C'&&ch2=='B'){
		return 1;
	}
	if(ch1=='D'&&ch2=='F'){
		return 1;
	}
	if(ch1=='F'&&ch2=='D'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string bb=f(b[0],b[1]),dd=f(d[0],d[1]);
	ll flag1=0,flag2=0;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(bb==dd&&a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(bb==dd&&a==c&&g(b[2])==g(d[2])){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(bb==dd&&a==c&&g(b[2])==g(d[2])&&h(b[2],d[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}