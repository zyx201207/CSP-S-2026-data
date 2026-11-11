#include <bits/stdc++.h>
#define int long long
using namespace std;
char s1[5];
char s2[5];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    cin>>c1;
    for(int i=0;i<3;i++){
        cin>>s1[i];

    }

    cin>>c2;
    for(int i=0;i<3;i++){
        cin>>s2[i];

    }
	bool shi=true;
    if(c1==c2){
        cout<<"1";
    }else {
    	cout<<"0";
    	shi=false;
	}

    if(s1[0]==s2[0] && s1[1]==s2[1] &&shi){
        cout<<"1";
    }else {
    	cout<<"0";
    	shi=false;
	}

    if((s1[2]=='A' || s1[2]=='B' ||s1[2]=='C' )&& (s2[2]=='A' || s2[2]=='B' ||s2[2]=='C' ) && shi) {
	
        cout<<"1";
    }else if((s1[2]=='D' || s1[2]=='E') && (s2[2]=='D' || s2[2]=='E') && shi) {
    	cout<<"1";
	}else {
    	cout<<"0";
    	shi=false;
	}

	if((s1[2]=='D' || s1[2]=='E') && (s2[2]=='D' || s2[2]=='E') && shi) {
    	cout<<"1";
	}else if((s1[2]=='A' || s1[2]=='B') && (s2[2]=='A' || s2[2]=='B') && shi) {
    	cout<<"1";
	}else if((s1[2]=='B' || s1[2]=='C') && (s2[2]=='B' || s2[2]=='C') && shi) {
    	cout<<"1";
	}else cout<<"0";

return 0;
}

