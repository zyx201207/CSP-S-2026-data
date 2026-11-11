#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int r1,r2,r3,r4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) r1=1;
	else r1=0;
	if(r1==1&&(s1.substr(0,2)==s2.substr(0,2))) r2=1;
	else r2=0;
	if(r2==1&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')) r3=1;
	else if(r2==1&&(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) r3=1;
	else r3=0;
	if(r3==1&&abs((int)s1[2]-(int)s2[2])==1) r4=1;
	else if(r3==1&&((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))) r4=1;
	else r4=0;
	cout<<r1<<r2<<r3<<r4<<endl; 
	return 0;
}
