#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		string p1,p2;
		char c1,c2;
		p1=s2[0]+s2[1];
		p2=s4[0]+s4[1];
		c1=s2[2];
		c2=s4[2];
		if(p1==p2){
			cout<<1;
			if(c1=='A'||c1=='B'||c1=='C'){
				if(c2=='A'||c2=='B'||c2=='C'){
					cout<<1;
					if(c1=='A'&&c2=='B') cout<<1;
					else if((c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')) cout<<1;
					else if(c1=='C'&&c2=='B') cout<<1;
					else cout<<0;
				}
				else cout<<"00";
			}
			else if(c1=='D'||c1=='F'){
				if(c2=='D'||c2=='F'){
					cout<<1;
					if(c1=='D'&&c2=='F') cout<<1;
					else if(c1=='F'&&c2=='D') cout<<1;
					else cout<<0;
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
