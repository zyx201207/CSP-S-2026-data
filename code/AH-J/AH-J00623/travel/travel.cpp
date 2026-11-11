#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool p1=false,p2=false,p3=false,p4=false;
char x,y;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	
		cin>>c1>>s1>>c2>>s2;
	

	if(c1[1]==c2[1]&&c1[0]==c2[0]) p1=true;
	if(p1==true){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			p2=true;
		}
	}
	if(p2==true){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]<='F'&&s2[2]<='F'&&s1[2]>='D'&&s2[2]>='D')){ 
			
	p3=true;
	}
}
		if(p3==true){
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='E'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='E')){
			p4=true;
			}
		}
	
	if(p1==true) 
	{cout<<1;
		}else if(p1==false){cout<<0;};
		if(p2==true) 
	{cout<<1;
		}else if(p2==false){cout<<0;};
		if(p3==true) 
	{cout<<1;
		}else if(p3==false){cout<<0;};
		if(p4==true) 
	{cout<<1;
		}else if(p4==false){cout<<0;};
	
	return 0;
}
