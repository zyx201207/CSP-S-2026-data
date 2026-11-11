#include <bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c==c2){
		cout<<1;
		if(s[0]==s2[0] && s[1]==s2[1]){
			cout<<1;
			if(s[2]=='F'){
				if(s2[2]=='D') cout<<11;				
			}else if(s[2]=='D'){
				if(s2[2]=='F') cout<<11;				
			}else if(s[2]=='A' || s[2]=='B' || s[2]=='C'){
				if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
					cout<<1;
					if(s[2]=='A' && s2[2]=='B') cout<<1;
					else if(s[2]=='B' && s2[2]=='C') cout<<1;
					else if(s[2]=='B' && s2[2]=='B') cout<<1;
					else if(s[2]=='C' && s2[2]=='B') cout<<1;
					else cout<<0;
				}else{
					cout<<"00";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else cout<<"0000";
	return 0;
}
