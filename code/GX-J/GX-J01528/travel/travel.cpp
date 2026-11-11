#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2; 
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	int a1=(s1[0]-'0')*10+s1[1]-'0';
	int a2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1!=a2){
		cout<<"1000";
		return 0;
	}
	int b1=1,b2=1,b3=0,b4=1;
	char q1=s1[2],q2=s2[2];
	bool p2=(q1=='D'||q1=='F')&&(q2=='D'||q2=='F');
    if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')) || p2){
	   b3=1;
	}
	if(p2){
		b4=1;
	}else if(q1=='B'||q2=='B'){
		b4=1;
	}else{
		b4=0;
	}
	cout<<b1<<b2<<b3<<b4;
    return 0;
}
