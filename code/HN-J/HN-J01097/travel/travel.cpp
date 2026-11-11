#include <bits/stdc++.h>
using namespace std;
string q,w,e,r;
string a,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>e>>r;
	if(q==e){
		cout<<1;
		a=w[0]+w[1];
		s=r[0]+r[1];
		if(a==s){
			cout<<1;
			if(((w[2]=='A'||w[2]=='C'||w[2]=='B')&&(r[2]=='A'||r[2]=='B'||r[2]=='C'))||((w[2]=='D'||w[2]=='F')&&(r[2]=='D'||r[2]=='F'))){
				cout<<1;
				if(((w[2]=='A'&&r[2]=='B')||(w[2]=='B'&&(r[2]=='C'||r[2]=='A'))||(w[2]=='C'&&r[2]=='B'))||((w[2]=='D'&&r[2]=='F')||(w[2]=='F'&&r[2]=='D'))) {
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
/*
wadddwwwwµÈÎÒdaddddadawdadadwdadadadadwwwwdawwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwea ewd wwqdxwwdw   w    wwwwww   e
efef




















































*/
 
 
