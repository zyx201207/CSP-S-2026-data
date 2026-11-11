#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,aa,b,bb;
	char a1,b1;
	cin>>a>>aa>>a1>>b>>bb>>b1;
	if(a==b) cout<<1;
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(aa==bb) cout<<1;
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if((a1=='F'&&b1=='D')||(a1=='D'&&b1=='F')){
		cout<<11;
		return 0;
	}
	else if((a1=='C'&&b1=='A')||(a1=='C'&&b1=='B')||(a1=='B'&&b1=='A')||(a1=='B'&&b1=='C')||(a1=='A'&&b1=='B')||(a1=='A'&&b1=='C')){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if((a1=='C'&&b1=='B')||(a1=='B'&&b1=='A')||(a1=='B'&&b1=='C')||(a1=='A'&&b1=='B')){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
