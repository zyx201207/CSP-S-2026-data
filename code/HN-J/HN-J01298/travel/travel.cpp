#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1=s1[0]*10-'0'+s1[1]-'0';
	int n2=s2[0]*10-'0'+s2[1]-'0';
	char m1=s1[2];
	char m2=s2[2];
	if(c1!=c2){
		cout<<"0000";
	}else if(c1==c2){
		if(n1!=n2){
			cout<<1000;
		}else if(n1==n2){
			if((m1=='D'&&m2=='F')||(m1=='A'&&m2=='B')||(m1=='B'&&m2=='C')||(m1=='A'&&m2=='C')||(m1=='F'&&m2=='D')||(m1=='B'&&m2=='A')||(m1=='C'&&m2=='B')||(m1=='C'&&m2=='A')){
				if((m1=='D'&&m2=='F')||(m1=='A'&&m2=='B')||(m1=='B'&&m2=='C')||(m1=='F'&&m2=='D')||(m1=='B'&&m2=='A')||(m1=='C'&&m2=='B')){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}
	}
	return 0;
} 
