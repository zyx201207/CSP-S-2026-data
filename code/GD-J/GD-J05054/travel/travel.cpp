#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,d,f,g;
	cin>>s>>d>>f>>g;
	if(s==f){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(d[1]==g[1]&&d[0]==g[0]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(g[2]=='A'||g[2]=='B'||g[2]=='C'))||((d[2]=='D'||d[2]=='F')&&(g[2]=='D'||g[2]=='F'))){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((d[2]=='A'&&g[2]=='B')||(d[2]=='B'&&g[2]=='A')||(d[2]=='B'&&g[2]=='C')||(d[2]=='C'&&g[2]=='B')||(d[2]=='D'&&g[2]=='F')||(d[2]=='F'&&g[2]=='D')){
		cout<<"1";	
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
