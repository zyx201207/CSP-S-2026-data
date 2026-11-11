#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
string a1,a2,b1,b2;
int n1,m1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	n1=int(a1[0]-'0')*10+int(a1[1]-'0');
	m1=int(b1[0]-'0')*10+int(b1[1]-'0');
	if(n1!=m1){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	n1=int(a2[0]-'0')*10+int(a2[1]-'0');
	m1=int(b2[0]-'0')*10+int(b2[1]-'0');
	if(n1!=m1){
		cout<<"000";
		return 0;
	}
	cout<<1;
	n1=int(a2[2]-'A');
	m1=int(b2[2]-'A');
	if((n1<3&&m1<3)||(n1>=3&&m1>=3)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(n1-m1)==1||n1+m1==8){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
