#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int box,chair;
	string chairs;
	char ch;
}r,x;
int f(string s){
	int c=0;
	c+=s[0]-'0';
	c*=10;
	c+=s[1]-'0';
	return c;
}
bool pd1(char a,char b){
	if((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='B'&&b=='A')||(a=='C'&&b=='A')||(a=='C'&&b=='B')){
		return 1;
	}
	if((a=='D'&&b=='E')||(a=='E'&&b=='D')){
		return 1;
	}
	return 0;
}
bool pd2(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='B'&&b=='A')||(a=='C'&&b=='B')){
		return 1;
	}
	if((a=='D'&&b=='E')||(a=='E'&&b=='D')){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.box>>r.chairs;
	cin>>x.box>>x.chairs;
	r.chair=f(r.chairs);
	x.chair=f(x.chairs);
	r.ch=r.chairs[2];
	x.ch=x.chairs[2];
	//cout<<r.ch<<" "<<x.ch;
	if(r.box==x.box){
		cout<<1;
		if(r.chair==x.chair){
			cout<<1;
			if(pd1(r.ch,x.ch)==1){
				cout<<1;
				if(pd2(r.ch,x.ch)==1){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
