#include<bits/stdc++.h>
using  namespace  std;
string  c1,s1,c2,s2;
int  ans=0;
void  init(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
}
void  solve(){
	for(int  i=0;i<c1.size();i++){
		if(s1[i]==s2[i]){
			ans++;
		}
	}
}
void  out(){
	bool  b=0,b1=0,b2=0;
	 
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
		b=1;
	}
	
	if(ans==2&&b==0){
		cout<<"1";
	}
	else{
		cout<<"0";
		b1=1;
		
	}
	
	if(b==0&&b1==0&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)){
		cout<<"1";
	}
	else{
		cout<<"0";
		b2=1;
	}
	
	if(b==0&&b1==0&&b2==0&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
}
int  main(){
	init();
	solve();
	out();
	return  0;
}
