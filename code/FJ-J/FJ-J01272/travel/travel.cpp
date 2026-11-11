#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,sz,t,tz;cin>>s>>sz>>t>>tz;
	if(s!=t)cout<<"0000"<<'\n';
	else{
		cout<<1;
		if(sz[0]!=tz[0]||sz[1]!=tz[1])cout<<"000"<<'\n';
		else{
			cout<<1;
			if((sz[2]=='D'||sz[2]=='F')&&(tz[2]=='A'||tz[2]=='B'||tz[2]=='C'))cout<<"00"<<'\n';
			else if((tz[2]=='D'||tz[2]=='F')&&(sz[2]=='A'||sz[2]=='B'||sz[2]=='C'))cout<<"00"<<'\n';
			else{
				cout<<1;
				if((sz[2]=='A'&&tz[2]!='B')||(sz[2]=='C'&&tz[2]!='B'))cout<<0<<'\n';
				else cout<<1<<'\n';
			}
		}
	}
	return 0;
}
