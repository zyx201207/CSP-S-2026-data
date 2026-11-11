#include<bits/stdc++.h>
using namespace std;
string x,y,a,b,s="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>a>>b;
	if(x==a){
		s+="1";
		if(y[0]==b[0] && y[1]==b[1]){
			s+="1";
			if((y[2]>='A' && y[2]<='C' && b[2]>='A' && b[2]<='C') || (y[2]>='D' && y[2]<='F' && y[2]>='D' && y[2]<='F')){
				s+="1";
				if(max(b[2],y[2])-min(b[2],y[2])==1){
					s+="1";
				}
				else s+="0";
			}
			else s+="00";
		}
		else s+="000";
	}
	else s+="0000"; 
	cout<<s;
	return 0;
} 
