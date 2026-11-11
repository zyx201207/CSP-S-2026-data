#include<bits/stdc++.h>
using namespace std;
string aa,bb;
char a[3],b[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa>>a[0]>>a[1]>>a[2];
	cin>>bb>>b[0]>>b[1]>>b[2];
	if(aa==bb&&a[0]==b[0]&&a[1]==b[1]&&((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C'))&&abs(a[2]-b[2])==1)cout<<1111;
	else if(aa==bb&&a[0]==b[0]&&a[1]==b[1]&&((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C')))cout<<1110;
	else if(aa==bb&&a[0]==b[0]&&a[1]==b[1])cout<<1100;
	else if(aa==bb)cout<<1000;
	else cout<<"0000";
	return 0;
} 
