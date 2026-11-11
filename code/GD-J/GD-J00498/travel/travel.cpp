#include<bits/stdc++.h>
#define int long long
using namespace std;

string C,c,S,s;

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>C>>S>>c>>s;
	
	if(C==c){
		cout<<"1";
		
		if(S[0]==s[0] && S[1]==s[1]){
			cout<<"1";
			
			if((S[2]=='F' && s[2]=='D') || (s[2]=='F' && S[2]=='D')) cout<<"11";
			else if(S[2]<='C' && S[2]>='A' && s[2]<='C' && s[2]>='A'){
				cout<<"1";
				if((S[2]=='A' && s[2]=='B') || (S[2]=='B' && s[2]=='A') || (S[2]=='C' && s[2]=='B') || (S[2]=='B' && s[2]=='C')) cout<<"1"; 
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
