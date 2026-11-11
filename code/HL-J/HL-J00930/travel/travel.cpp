#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,y,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>x>>a>>y>>b;
	c=int(a[0]-'0')*10+a[1]-'0';
	d=int(b[0]-'0')*10+b[1]-'0';
	if(x==y) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(c==d)	cout<<1;
	else cout<<0;
	if(c==d){
		if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C')		cout<<1;
			else cout<<0;
		}
		else if(b[2]=='D'||b[2]=='F')		cout<<1;
		else    cout<<0;
	}
	else{
		cout<<0;
	}
	if(c==d){
		if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='C')||(a[2]=='D'&&b[2]=='F')) cout<<1;
		else if((b[2]=='A'&&a[2]=='B')||(b[2]=='B'&&a[2]=='C')||(b[2]=='D'&&a[2]=='F'))	cout<<1;
		else	cout<<0;
	}
	else{
		cout<<0;
	}
	return 0;
}