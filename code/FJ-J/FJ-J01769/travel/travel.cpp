#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,d,e;
	char c,f;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	cin>>e;
	cin>>f;
	if(a==d){
	cout<<1;
	if(b==e){
	cout<<1;
	if(c=='A'||c=='B'||c=='C'&&f=='A'||f=='B'||f=='C'){
	cout<<1;
	if(c-f==-1||c-f==1)
	cout<<1;
	else
	cout<<0;
	}
	else if(c=='D'||c=='F'&&f=='D'||f=='F'){
	cout<<1;
	if(c-f==-1||c-f==1)
	cout<<1;
	else
	cout<<0;
	}
	else
	cout<<0<<0;
}
	else
	cout<<0<<0<<0;
}
	else
	cout<<0<<0<<0<<0;
	return 0;
}
