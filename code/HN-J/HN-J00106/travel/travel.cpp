#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
	cout<<1;
	if(b[0]==d[0] and b[1]==d[1]){
	cout<<1;
	if(((b[2]=='D' and d[2]=='F') or (b[2]=='F' and d[2]=='D')) or ((b[2]!='D' and d[2]!='F') and (b[2]!='F' and d[2]!='D'))){
	cout<<1;	
	if(((int)(b[2])+1==(int)(d[2])) or ((int)(d[2])+1==(int)(b[2]))) cout<<1;
	else{
	if((b[2]=='D' and d[2]=='F') or (b[2]=='F' and d[2]=='D')) cout<<1;
	else cout<<"0";	
	} 	
	}
	else cout<<"00";
	}
	else cout<<"000";	
	}
	else cout<<"0000";
	
	
	
	return 0;
}
