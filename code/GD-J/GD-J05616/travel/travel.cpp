#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[10],s2[10],z[10],h[10]; //02 01A 02 01B
	cin>>c1;
	bool a=false,b=false,c=false,d=false;
	for(int i=0;i<3;i++){
		cin>>s1[i];
		z[i]=s1[i];
		
	} 
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
		h[i]=s2[i];
	} 
	if(c1==c2) a=true;
	if(z[0]==h[0]&&z[1]==h[1]) b=true;
	if((z[2]=='A'||z[2]=='B'||z[2]=='C' && h[2]=='A'||h[2]=='B'||h[2]=='C')||(z[2]=='D'||z[2]=='F' && h[2]=='D'||h[2]=='F')) c=true;	
	if((z[2]=='A'&&h[2]=='B')||(z[2]=='B'&&h[2]=='A')||(z[2]=='B'&&h[2]=='C')||(z[2]=='C'&&h[2]=='B')||(z[2]=='D'&&h[2]=='F')||(z[2]=='F'&&h[2]=='D')) d=true;
	
	if(a==true && b==true && c==true && d==true) cout<<"1111";
	else if(a==true && b==true && c==true && d==false) cout<<"1110";
	else if(a==true && b==true && c==false && d==false) cout<<"1100";
	else if(a==true && b==false && c==false && d==false) cout<<"1000";
	else if(a==true && b==false && c==true && d==true) cout<<"1000";
	else if(a==true && b==false && c==true && d==false) cout<<"1000";
	else if(a==true && b==false && c==false && d==true) cout<<"1000";
	else if(a==false && b==false && c==false && d==false) cout<<"0000";
	else cout<<"0000";
	return 0;
} 
