#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char a1,b1;
	cin>>c1>>s1>>a1>>c2>>s2>>b1;
	
	bool a=1,b=1,c=0;
	if(c1!=c2){
		a=0;
		cout<<0;
	}
	if(a==1) cout<<1;
	if(s1!=s2) b=0; 
	if(b==1&&a==1){
		cout<<1;
	}
	if(b==0||a==0)cout<<0;
	if(a==1&&b==1&&a1>='A'&&a1<='C'&&b1>='A'&&b1<='C'||a1>='D'&&a1<='F'&&b1>='D'&&b1<='F'){
		c=1;
		cout<<1;
	}
	if(c==0)cout<<0;
	if(a==1&&b==1&&c==1){
		if(a1=='D'){
			if(a1+2==b1){
				cout<<1;
				return 0;
			}
		}
		if(a1=='F'){
			if(a1-2==b1){
				cout<<1;
				return 0;
			}
		}
		if(a1=='C'){
			if(a1-1==b1){
				cout<<1;
				return 0;
			}
		}
		else{
			if(a1-1==b1||a1+1==b1){
				cout<<1;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
} 
