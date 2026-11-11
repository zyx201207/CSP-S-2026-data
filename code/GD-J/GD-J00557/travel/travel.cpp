#include<bits/stdc++.h>
using namespace std;
string n1,n2;
string m1,m2;
int main (){
	cin>>n1>>m1>>n2>>m2;
	if(n1!=n2){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(m1[0]!=m2[0]||m1[1]!=m2[1]){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if(m1[2]=='A'||m1[2]=='B'||m1[2]=='C'){
		if(m2[2]=='D'||m2[2]=='F'){
			cout<<"00";
			return 0;
		}
		cout<<1;
		if(m1[2]!='B'&&m2[2]!='B'){
			cout<<'0';
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(m2[2]!='D'&&m2[2]!='F'){
		cout<<"00";
		return 0;
	}
	cout<<11;
	return 0;
}

