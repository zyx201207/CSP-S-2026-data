#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		a=a*10+c1[i]-48;
	}
	for(int i=0;i<s1.size()-1;i++){
		b=b*10+s1[i]-48;
	}
	for(int i=0;i<c2.size();i++){
		c=c*10+c2[i]-48;
	}
	for(int i=0;i<s2.size()-1;i++){
		d=d*10+s2[i]-48;
	}
	e=s1[s1.size()-1];
	f=s2[s2.size()-1];
	//cout<<e<<f;
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<" ";
	if(a!=c){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	if(b==d){
		cout<<1;
		if(e=='F'||f=='F'||e=='D'||f=='D'){
			if(e=='F'&&f=='D'||e=='D'&&f=='F'){
				cout<<"11";
				return 0;
			}
			cout<<"00";
			return 0;
		}else{
			cout<<1;
			if(e-f==1||e-f==-1){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<"000";
		return 0;
	}
	return 0;
}
