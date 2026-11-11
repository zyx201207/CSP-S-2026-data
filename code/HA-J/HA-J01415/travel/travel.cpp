#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1=0,c2=0,c3=0,c4=0,R,X;
	int a[3];
	string b[3];
	for(int i=0;i<2;i++){
		cin>>a[i]>>b[i];
	}
	if(a[0]==a[1]) c1=1;
	if(c1==1){
		if(b[0][0]==b[1][0]&&b[0][1]==b[1][1]){
			c2=1;
		}
	}
	if(c2==1){
		if(b[0][2]=='A'||b[0][2]=='B'||b[0][2]=='C') R=1;
		else R=2;
		if(b[1][2]=='A'||b[1][2]=='B'||b[1][2]=='C') X=1;
		else X=2;
		if (R==X) c3=1;
	}
	if(c3==1){
		if(b[0][2]=='D'&&b[1][2]=='F'||b[0][2]=='F'&&b[1][2]=='D') c4=1;
		if(abs(b[0][2]-b[1][2])==1) c4=1;
		
	}
	cout<<c1<<c2<<c3<<c4;
	return 0;
}
