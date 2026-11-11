#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string co,so,ct,st;
	cin>>co>>so>>ct>>st;
	if(co==ct){
		if(so[0]==st[0] && so[1]==st[1]){
			if((so[2]=='A' && st[2]=='B') || (so[2]=='B' && st[2]=='A') || (so[2]=='A' && st[2]=='C') || (so[2]=='C' && st[2]=='A') || (so[2]=='B' && st[2]=='C') || (so[2]=='C' && st[2]=='B') || (so[2]=='D' && st[2]=='E') || (so[2]=='E' && st[2]=='D')){
				if(abs(so[2]-st[2])==1 && !((so[2]=='D' && st[2]=='C') || (so[2]=='C' && st[2]=='D'))){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
