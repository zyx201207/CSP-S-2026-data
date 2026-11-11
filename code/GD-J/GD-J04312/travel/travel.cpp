#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(s2[2]=='F')s2[2]='E';
	if(c2[2]=='F')c2[2]='E';
	if(c1==s1)a=1;
	if(a&&c2[0]==s2[0]&&c2[1]==s2[1])b=1;
	if(b){
		if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')c=1;
		}
		else{
			if(s2[2]=='D'||s2[2]=='E')c=1;
		}
	}
	if(c&&(abs(c2[2]-s2[2])==1))d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
