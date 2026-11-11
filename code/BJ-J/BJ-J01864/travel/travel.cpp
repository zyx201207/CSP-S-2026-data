#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a,b;
	a=c1[0]-'0';
	a*=10;
	a+=c1[1]-'0';
	b=c2[0]-'0';
	b*=10;
	b+=c2[1]-'0';
	if(a==b){
		int z1,z2;
		z1=s1[0]-'0';
		z1*=10;
		z1+=s1[1]-'0';
		z2=s2[0]-'0';
		z2*=10;
		z2+=s2[1]-'0';
		if(z1==z2){
			char h1,h2;
			h1=s1[2];
			h2=s2[2];
			cout<<"11";
			if(h1=='A'&&h2=='B'){
				cout<<"11";
			}
			else if(h1=='A'&&h2=='C'){
				cout<<"10";
			}
			else if(h1=='B'&&h2=='C'){
				cout<<"11";
			}
			else if(h1=='D'&&h2=='F'){
				cout<<"11";
			}
			else if(h1=='B'&&h2=='A'){
				cout<<"11";
			}
			else if(h1=='C'&&h2=='A'){
				cout<<"10";
			}
			else if(h1=='C'&&h2=='B'){
				cout<<"11";
			}
			else if(h1=='F'&&h2=='D'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
