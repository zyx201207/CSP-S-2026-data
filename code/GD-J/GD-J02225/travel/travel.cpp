#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c,s,a,d;
	int z=0,q=0,e=0,m=0;
	cin>>c>>s>>a>>d;
	if(c==a){
		cout<<"1";
		q=1;
	}
	else
		cout<<"0";
	if(s[0]==d[0]&&s[1]==d[1]&&q==1){
		cout<<"1";
		m=1;
		
	}
	else
		cout<<"0";
	if(s[2]=='C'&&d[2]=='D'){
		z=0;
	}
	else if(s[2]=='D'&&d[2]=='C'){
		z=0;
	}
	else if((s[2]=='A'||'B'||'C')&&(d[2]=='A'||'B'||'C')&&q==1&&m==1){
		z = 1;		
				
	}
	else if((s[2]=='D'||'E')&&(d[2]=='D'||'E')&&q==1&&m==1){
		z = 1;			
	}
	if(m==1&&z==1){
		cout<<"1";
		e =1;
	}
	else
		cout<<"0";
	if(q==1&&e==1&&(s[2]+1==d[2]||s[2]-1==d[2])){
		cout<<"1";
	}
	else
		cout<<"0";
	return 0;
}
