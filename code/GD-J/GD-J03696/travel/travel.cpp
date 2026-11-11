#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char c1,c2,ch;
	cin>>a1>>a2>>c1>>b1>>b2>>c2;
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}
	if(a2!=b2){
		cout<<"1000";
		return 0;
	}
	if(c1>c2){
		ch=c1;
		c1=c2;
		c2=ch;
	}
	if(c1<'D'&&c2>'C'){
		cout<<"1100";
		return 0;
	}
	if(c1=='A'&&c2=='C'){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
} 
