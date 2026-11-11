#include<bits/stdc++.h>
#define int long long

using namespace std;
string c1,s1,c2,s2;
bool f1=0,f2=0,f3=0,f4=0;
int a1,a2;char b1,b2;

signed main(){
	ios::sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[0]+s1[1];a2=s2[0]+s2[1];
	b1=s1[2];b2=s2[2];
	if(c1==c2)f1=1;
	if(f1==1&&a1==a2)f2=1;
	if(f2==1){
		if((b1=='F'&&b2=='D')||(b1=='D'&&b2=='F'))f3=f4=1;
		if((b1=='A'&&b2=='B')||(b1=='B'&&b2=='A'))f3=f4=1;
		if((b1=='A'&&b2=='B')||(b1=='B'&&b2=='A'))f3=f4=1;
		if((b1=='A'&&b2=='C')||(b1=='C'&&b2=='A'))f3=1;
	}
	
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
 
