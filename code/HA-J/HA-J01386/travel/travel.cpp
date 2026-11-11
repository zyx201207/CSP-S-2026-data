#include<bits/stdc++.h>
using namespace std;
int main(){
	// a
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char x,y;
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b==d){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='A'&&y=='C')||(x=='C'&&y=='A')||x=='C'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(((x=='A'&&y=='B')||(x=='B'&&y=='A')||x=='C'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
		cout<<1;
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
