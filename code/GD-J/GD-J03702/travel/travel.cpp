#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	bool l=1;
	if(c1==c2)cout<<1;
	else {
		cout<<0;
		l=0;
	}
	if(l&&s1[1]==s2[1]&&s1[0]==s2[0])cout<<1;
	else{
		cout<<0;
		l=0;
	}
	if(l){
		char x=s1[2],y=s2[2];
		if((x=='C'&&y=='B')||(x=='C'&&y=='A')||(x=='A'&&y=='B')||(x=='A'&&y=='C')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))cout<<1;
		else if((x=='C'&&y=='D')||(x=='D'&&y=='C')){
			cout<<0;
			l=0;
		}
		else{
			cout<<0;
			l=0;
		}
	}
	else{
		cout<<0;
		l=0;
	}
	if(l){
		char x=s1[2],y=s2[2];
		if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='B'&&y=='A')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
