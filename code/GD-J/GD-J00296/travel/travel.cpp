#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)cout<<"1";
    else{
    	cout<<"0000";
    	return 0;
	}
    if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<"1";
    else{
    	cout<<"000";
    	return 0;
	}
    if(a2[2]>='A'&&a2[2]<='C'){
    	if(b2[2]>='A'&&b2[2]<='C')cout<<"1";
    	else{
    		cout<<"00";
    		return 0;
		}
	}else{
		if(b2[2]=='D'||b2[2]=='F')cout<<"1";
		else{
    		cout<<"00";
    		return 0;
		}
	}
	int c=a2[2]-'A',d=b2[2]-'A';
	if(c==2&&d==3||c==3&&d==2)cout<<"0";
	else if(abs(c-d)==1||c==5&&d==3||c==3&&d==5)cout<<"1";
	else cout<<"0";
	return 0;
} 
