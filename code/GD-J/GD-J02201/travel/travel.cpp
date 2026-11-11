#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[4];
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a[0]='1';
	else a[0]='0';
	
	if(s1[1]==s2[1]&&a[0]=='1')a[1]='1';
	else a[1]='0';
	
	if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||
	(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&a[1]=='1')a[2]='1';
	else a[2]='0';
	
	if(a[2]=='1'&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&abs(s1[2]-s2[2])==1)
	||((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))))a[3]='1';
	else a[3]='0';
	
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
