#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	int bus1,bus2;
	bool jk=1;
	cin>>bus1>>a>>bus2>>b;
	
	if(bus1==bus2)cout<<1;
	else {
	cout<<0;
	jk=0;}
	
	
	if(a[0]==b[0]&&a[1]==b[1]&&jk)cout<<1;
	else {
	cout<<0;
	jk=0;}
	
	
	if((a[2]>='A'&&a[2]<='C')&&(b[2]>='A'&&b[2]<='C')&&jk)cout<<1;
	else if((a[2]=='D'&&a[2]=='F')&&(b[2]=='D'&&b[2]=='F')&&jk)cout<<1;
	else {
	cout<<0;
	jk=0;}
	
	
	if((a[2]-b[2]==1||a[2]-b[2]==-1)&&jk)cout<<1;
	else cout<<0;
	
	
	return 0;
}
