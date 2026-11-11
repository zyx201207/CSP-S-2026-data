#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		int x1=(a2[0]-'0')*10+a2[1]-'0',x2=(b2[0]-'0')*10+b2[1]-'0';
		if(x1==x2){
			cout<<1;
			if(!((a2[2]<='C')^(b2[2]<='C'))){
				cout<<1;
				if(a2[2]=='A'&&b2[2]=='B')cout<<1;
				else if(a2[2]=='A'&&b2[2]=='B')cout<<1;
				else if(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C'))cout<<1;
				else if(a2[2]=='C'&&b2[2]=='B')cout<<1;
				else if(a2[2]=='D'&&b2[2]=='F')cout<<1;
				else if(a2[2]=='F'&&b2[2]=='D')cout<<1;
				else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
} 
