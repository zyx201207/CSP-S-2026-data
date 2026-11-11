#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else if(b[0]!=d[0]||b[1]!=d[1]) cout<<"1000";
	else{
		bool ok[2];
		if(b[2]=='A'||b[2]=='B'||b[2]=='C') ok[0]=true;
        else ok[0]=false;
		if(d[2]=='A'||d[2]=='B'||d[2]=='C') ok[1]=true;
        else ok[1]=false;
        if(ok[0]!=ok[1]) cout<<"1100";
        else{
        	if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')) cout<<"1110";
        	else cout<<"1111";
		}
	}
	return 0;
} 
