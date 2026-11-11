#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int s[5],x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a2[2]=='A') x1=0;
	if(a2[2]=='B') x1=1;
	if(a2[2]=='C') x1=2;
	if(a2[2]=='D') x1=4;
	if(a2[2]=='E') x1=5;
	if(b2[2]=='A') x2=0;
	if(b2[2]=='B') x2=1;
	if(b2[2]=='C') x2=2;
	if(b2[2]=='D') x2=4;
	if(b2[2]=='E') x2=5;
	if(a1!=b1){
		s[1]=0;
		s[2]=0;
		s[3]=0;
	}else{
		s[1]=1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			s[2]=1;
			if(x1<=2&&x2<=2){
				s[3]=1;
			}else if(x1>=3&&x2>=3){
				s[3]=1;
			}else{
				s[3]=0;
			}
		}else{
			s[2]=0;
			s[3]=0;
		}
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		if(x1+1==x2||x1-1==x2){
			s[4]=1;
		}else s[4]=0;
	}else s[4]=0;
	cout<<s[1]<<s[2]<<s[3]<<s[4];
	return 0;
}
