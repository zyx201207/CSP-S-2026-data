#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char w1=s1[2];
	char w2=s2[2];
	int a1,a2,t=0;
	if(c1==c2) {cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(w1=='A'||w1=='B'||w1=='C') a1=1;
			else a1=2;
			if(w2=='A'||w2=='B'||w2=='C') a2=1;
			else a2=2;
			if(a1==a2) {cout<<"1";
				if(w1=='A'&&w2=='B'){
				cout<<"1";
				t=1;}
				if(w1=='B'&&w2=='A'){
				cout<<"1";
				t=1;}
				if(w1=='C'&&w2=='B'){
				cout<<"1";
				t=1;}
				if(w1=='B'&&w2=='C'){
				cout<<"1";
				t=1;}
				if(w1=='F'&&w2=='D'){
				cout<<"1";
				t=1;}
				if(w1=='D'&&w2=='F'){
				cout<<"1";
				t=1;}
				if(t==0)cout<<"0";
				}
			else cout<<"00";
			
			}
		else cout<<"000";
		}
	else cout<<"0000";
	return 0;
	fclose("travel.in");
	fclose("travel.out");
	
}
