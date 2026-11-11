#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,n=1,p[3];
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		p[0]=1;
	}if((c[0]==d[0])||(c[1]==d[1])){
		p[1]=1;
	}
	if((c[2]=='D'||'F')&&(d[2]=='F'||'D')){
		p[2]=1;
		p[3]=1;
	}else{
		if((c[2]=='A'||'B'||'C')&&(d[2]=='A'||'B'||'C')){
			p[2]=1;
		}
		if(((c[2]=='A')&&(d[2]=='B'))||((c[2]=='B')&&(d[2]=='A'||'B'))||((c[2]=='C')&&(d[2]=='B'))){
			p[3]=1;
		}
	}
	for(int i=0;i<4;i++){
		cout<<p[i];
	}	
	
	
	return 0;
} 
