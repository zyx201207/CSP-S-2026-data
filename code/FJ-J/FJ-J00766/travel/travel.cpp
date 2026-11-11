#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,seta,setb;
	cin>>a>>seta>>b>>setb;
	if(a!=b) {cout<<"0000";return 0;}
	cout<<1;
	if(seta[0]==setb[0]&&seta[1]==setb[1]) cout<<1;
	else {cout<<"000";return 0;}
	if(seta[2]=='A'||seta[2]=='B'||seta[2]=='C'){
		if(setb[2]=='A'||setb[2]=='B'||setb[2]=='C')
			cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(seta[2]=='D'||seta[2]=='E'){
		if(setb[2]=='D'||setb[2]=='E')
			cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(abs(seta[2]-setb[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
