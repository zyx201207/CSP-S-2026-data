#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	string p1=c1.substr(0,2),p2=c2.substr(0,2);
	char z1=c1[2],z2=c2[2];
	if(s1==s2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if(((z1>='A'&&z1<='C')&&(z2>='A'&&z2<='C'))||((z1=='D'||z1=='F')&&(z2=='D'||z2=='F'))){
				cout<<"1";
				if((z1=='A'&&z2=='B')||(z2=='A'&&z1=='B')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='B')||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
