#include <bits/stdc++.h>
using namespace std;

struct NODE{
	string c,s;
};
NODE a[10];
string ans;bool flag;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>a[1].c>>a[1].s>>a[2].c>>a[2].s;
	if(a[1].c==a[2].c) ans+='1';
	else{
        cout <<"0000";
        return 0;
	}
	if(a[1].s[0]==a[2].s[0] && a[1].s[1]==a[2].s[1]){
        ans+='1';
	}else{
	    cout <<"1000";
	    return 0;
	}
	if((a[1].s[2]<='F' && a[1].s[2]>='D' && a[2].s[2]<='F' && a[2].s[2]>='D') || (a[1].s[2]>='A' && a[1].s[2]<='C' && a[2].s[2]>='A' && a[2].s[2]<='C')){
        ans+='1';
	}else{
	    cout <<"1100";
	    return 0;
	}
	if(a[1].s[2]-a[2].s[2]>=-1 && a[1].s[2]-a[2].s[2]<=1 && ((a[1].s[2]!='C' && a[2].s[2]!='D') && (a[1].s[2]!='D' && a[2].s[2]!='C'))){
        ans+='1';
	}else{
	    cout <<"1110";
	    return 0;
	}
	cout <<ans;
}
