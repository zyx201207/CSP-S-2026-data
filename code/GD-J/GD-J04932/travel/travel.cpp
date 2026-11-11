#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) ans1=1;
	else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) ans2=1;
	else{
		cout<<"1000";
		return 0;
	}
	if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')) ans3=1;
	else {
		cout<<"1100";
		return 0;
	}
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(d[2]=='A'&&b[2]=='B')||(d[2]=='B'&&b[2]=='C')||(d[2]=='D'&&b[2]=='F')) ans4=1;
	else {
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
