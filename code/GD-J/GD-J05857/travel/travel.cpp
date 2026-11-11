#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	
	int a=(s1[0]-'0')*10+(s1[1]-'0'),c=(s3[0]-'0')*10+(s3[1]-'0');
	int b=(s2[0]-'0')*10+s2[1]-'0',d=(s4[0]-'0')*10+(s4[1]-'0');
	char x=s2[2],y=s4[2];
	if(a==c and a!=1 and a!=16){
		cout<<1;
		if(b==d){
			cout<<1;
			if(x=='A' and y=='B'){
				cout<<1;
				cout<<1;
			}
			else if(x=='A' and y=='C'){
				cout<<1<<0;
			}
	
			else if(x=='B' and y=='C'){
				cout<<1;
				cout<<1;
			}
			else if(x=='D' and y=='F'){
				cout<<1;
				cout<<1;
			}
			
			else if(y=='A' and x=='B'){
				cout<<1;
				cout<<1;
			}
			else if(y=='A' and x=='C'){
				cout<<1<<0;
			}
			else if(y=='B' and x=='C'){
				cout<<1;
				cout<<1;
			}
			else if(y=='D' and x=='F'){
				cout<<1;
				cout<<1;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
}
