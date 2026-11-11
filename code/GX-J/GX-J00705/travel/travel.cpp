#include <bits/stdc++.h>
using namespace std;
int k=0,n=0,b=0,m=0,n1=0;
string x1,x2,x3,x4;
int main (){
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>x3>>x4;
	if(x1==x3){
		cout<<1;
		b=1;
	}else{
		cout<<0;
	}
	if(x2[0]==x4[0]&&b==1){
		if(x2[1]==x4[1]&&b==1){
			cout<<1;
			k=1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
		if(x4[2]=='A'||x4[2]=='B'||x4[2]=='C'){
			if(k==1){
				cout<<1;
				n=1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else if(x2[2]=='D'||x2[2]=='F'){
		if(x4[2]=='D'||x4[2]=='F'){
			if(k==1){
				cout<<1;
				n1=1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(n1==1){
		cout<<1;
	}else if(n==1){
		if(x2[2]=='A'&&x4[2]=='B'){
			cout<<1;
		}else if(x2[2]=='B'&&x4[2]=='C'){
			cout<<1;
		}else if(x4[2]=='B'&&x2[2]=='C'){
			cout<<1;
		}else if(x4[2]=='B'&&x2[2]=='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
