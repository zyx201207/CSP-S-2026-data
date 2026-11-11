#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool a,b,c,d;
	if(a1==b1)a=1;
	
	
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&a==1)b=1;
	if(((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D'))&&b==1)c=1;
	if(max(a2[2],b2[2])-min(a2[2],b2[2])==1&&c==1)d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
