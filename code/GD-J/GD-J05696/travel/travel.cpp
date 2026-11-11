#include<bits/stdc++.h>
using namespace std;
int c1,c2,q1,q2;
string s1,s2;
char k1,k2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	q1=(s1[0]-'0')*10+(s1[1]-'0');
	q2=(s2[0]-'0')*10+(s2[1]-'0');
	if(q1==q2)cout<<1;
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	k1=s1[2];
	k2=s2[2];
	if(k1=='A'&&k2=='B'||k1=='B'&&k2=='A'||k1=='A'&&k2=='C'||k1=='B'&&k2=='C'||k1=='C'&&k2=='A'||k1=='C'&&k2=='B'||k1=='F'&&k2=='D'||k1=='D'&&k2=='F'){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(k1=='A'&&k2=='B'||k1=='B'&&k2=='A'||k1=='B'&&k2=='C'||k1=='C'&&k2=='B'||k1=='F'&&k2=='D'||k1=='D'&&k2=='F'){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
