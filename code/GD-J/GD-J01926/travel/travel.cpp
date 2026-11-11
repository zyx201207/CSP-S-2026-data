#include <bits/stdc++.h>
using namespace std;
int a,b;
string c[5];
int main(){
    cin>>a>>c[1]>>b>>c[2];
    if(a==b)cout<<"1";
    else{
    	cout<<"0000";
	    return 0;
	}
    if(c[1][0]==c[2][0]&&c[1][1]==c[2][1])cout<<"1";
    else{
    	cout<<"000";
		return 0;
	}
    if(c[1][2]+c[2][2]<=134||c[1][2]+c[2][2]==138)cout<<"1";
    else{
    	cout<<"00";
    	return 0;
	}if(c[1][2]+1==c[2][2]||c[1][2]-1==c[2][2]||(c[1][2]==68&&c[2][2]==70))cout<<"1";
	else cout<<"0";
	return 0;
}
