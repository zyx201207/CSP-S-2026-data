#include <bits/stdc++.h>
using namespace std;
main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int x,a;
	string y,b;
	cin>>x>>y>>a>>b;
	if(x!=a){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(y[0]==b[0]&&y[1]==b[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((y[2]=='A'||'B'||'C')&&(b[2]!='A'||'B'||'C'))||((y[2]=='D'||'E')&&(b[2]!='D'||'E'))){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	}
	for(int i=65;i<=69;i++){
		if((int(y[2])+1==int(b[2]))||(int(y[2])-1==int(b[2]))){
		cout<<"1";
		return 0;
		}
		else{
		cout<<"0";
		return 0;
		}
	}
	return 0;
} 
