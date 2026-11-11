#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
bool check(char c1,char c2){
	if(c1=='A'&&c2=='B')return 0;
	if(c1=='B'&&c2=='C')return 0;
	if(c1=='D'&&c2=='F')return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdout);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	if((c[0]!=d[0])||(c[1]!=d[1])){
		cout<<"1000";
		return 0;
	}
	if((c[2]<='C'&&d[2]>='D')||(c[2]>='D'&&d[2]<='C')){
		cout<<"1100";
		return 0;
	}
	if(check(c[2],d[2])&&check(d[2],c[2])){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
