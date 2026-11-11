#include<bits/stdc++.h>
using namespace std;
int a,b,o=1,c,d;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>c>>s1;
	cin>>b;
	cin>>d>>s2;
	if(a==b){
		cout<<o;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c==d){
		cout<<o;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1>='A' && s1<='C' && s2>='A' && s2<='C'){
		cout<<o;
		if(s1=='A' || s2=='A'){
			if(s1=='B' || s2=='B'){
				cout<<o;
			}else{
				cout<<0;
			}
			return 0;
		}
	}else{
		cout<<0;
	}
	if(s1>='D' && s1<='E' && s2>='D' && s2<='E'){
		cout<<o<<o;
		return 0;
	}else{
		cout<<0;
	}
	if(s1=='B' || s2=='B'){
		if(s1=='C' || s2=='C'){
			cout<<o;
		}else{
			cout<<0;
		}
		return 0;
	}
	return 0;
} 
