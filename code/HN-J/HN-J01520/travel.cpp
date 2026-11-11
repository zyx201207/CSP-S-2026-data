#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1==s1){
		a=1;
		if(c2[0]+c2[1]==s2[0]+s2[1]){
			b=1;
			if((c2[3]=='A'||c2[3]=='B'||c2[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))
		c=1;
		else if((c2[3]=='E'||c2[3]=='F')&&(s2[3]=='E'||s2[3]=='F'))
		c=1;
		else c=0;
		if((c2[3]=='A'&&s2[3]=='B')||(c2[3]=='B'&&s2[3]=='A'))
		d=1;
		else if((c2[3]=='B'&&s2[3]=='C')||(c2[3]=='C'&&s2[3]=='B'))
		d=1;
		else if((c2[3]=='E'&&s2[3]=='F')||(c2[3]=='F'&&s2[3]=='E'))
		d=1;
		else d=0;
		}
		else b=0; 
			
		}
		
	else a=0;
	
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
}
