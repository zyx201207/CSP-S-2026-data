#include<bits/stdc++.h>
using namespace std;
string c,s,b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>b>>d;
	if(s[2]=='F')	s[2]='E';
	if(d[2]=='F')	d[2]='E';
	if(c==b){
		cout<<"1";
		if(s[0]==d[0] && s[1]==d[1]){
			cout<<"1";
			int x=0,y=0;
			if(s[2]=='E' || s[2]=='D')	x=1;
			if(d[2]=='E' || d[2]=='D')	y=1;
			if(x==y){
				cout<<"1";
				int p=(int)(s[2]-d[2]);
				if(p==1 || p==-1)	cout<<"1";
				else	cout<<"0";
			}
			else	cout<<"00";
		}
		else	cout<<"000";
	}
	else	cout<<"0000";
	return 0;
}
