#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	bool b=1;
	if(cr==cx) cout<<1;
	else{
		cout<<0;
		b=0;
	}
	if(b==0) cout<<0;
	else if(sr[0]==sx[0]&&sr[1]==sx[1]) cout<<1;
	else{
		cout<<0;
		b=0;
	}
	if(b==0) cout<<0;
	else if((int(sr[2])>=68&&int(sr[2])<=70)&&(int(sx[2])>=68&&int(sx[2])<=70))
		cout<<1;
	else if((int(sr[2])>=65&&int(sr[2])<=67)&&(int(sx[2])>=65&&int(sx[2])<=67))
		cout<<1;
	else{
		b=0;
		cout<<0;
	}
	if(b==0) cout<<0;
	else if(int(sr[2])-int(sx[2])==1||int(sr[2])-int(sx[2])==-1)
		cout<<1;
	else cout<<0; 
	return 0;
}

