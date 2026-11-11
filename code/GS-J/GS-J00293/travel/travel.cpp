#include <bits/stdc++.h>
using namespace std;
int a,b,x,y,m=2,n=3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	for(int i=0;i<=1;i++){
		a=a*10+s1[i]-'0';
	}
	for(int i=0;i<=1;i++){
		b=b*10+s2[i]-'0';
	}
	//cout<<a<<b;
	if(c1==c2&&a==b){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		x=1;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		y=1;
	}
	if(s2[2]=='D'||s2[2]=='F'){
		m=1;
	}
	if(s1[2]=='D'||s1[2]=='F'){
		n=1;
	}
	if(c1==c2&&a==b&&x==y){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&a==b&&x==y){
		if(abs(s1[2]-s2[2])==1||m==n){
			cout<<"1";
		}else{
		cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
