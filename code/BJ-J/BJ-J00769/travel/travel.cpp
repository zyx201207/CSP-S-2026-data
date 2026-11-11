#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans[0]='1';
	else{
        cout<<"0000";
        return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) ans[1]='1';
	else{
        cout<<"1000";
        return 0;
	}
    if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') ans[2]='1';
    else if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) ans[2]='1';
    else{
        cout<<"1100";
        return 0;
    }
    if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) {
        cout<<"1111";
        return 0;
    }
    else{
        cout<<"1110";
        return 0;
    }
	return 0;
}
