#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cx1,cx2,h1,h2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.length();i++){
		cx1*=10;
		cx1+=c1[i]-'0';
	}
	for(int i=0;i<c2.length();i++){
		cx2*=10;
		cx2+=c2[i]-'0';
	}
	for(int i=0;i<s1.length()-1;i++){
		h1*=10;
		h1+=s1[i]-'0';
	}
	for(int i=0;i<s2.length()-1;i++){
		h2*=10;
		h2+=s2[i]-'0';
	}
	if(cx1==cx2){
		a=1;
		if(h1==h2){
			b=1;
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				c=1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')){
					d=1;
				}
			}
			if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
				c=1;
				d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
