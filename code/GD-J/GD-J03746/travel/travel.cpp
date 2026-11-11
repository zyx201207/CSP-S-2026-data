#include<bits/stdc++.h>
using namespace std;
int a,c,s,e[5];
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;	
	s=abs(b[2]-d[2]);
	if(a==c){
		e[1]=1;	
	if(b[0]==d[0]&&b[1]==d[1]){
		e[2]=1;
		if((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')){
		e[3]=1;
		if(s==1){
			e[4]=1;
		}
	    }
	   }	
    }
	cout<<e[1]<<e[2]<<e[3]<<e[4]; 
	return 0;  
}
