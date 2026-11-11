#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	long long p=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else {cout<<"0000";return 0;}
	int r=int(s1[0])*10+int(s1[1]);
	int l=int(s2[0])*10+int(s2[1]);
	if(l==r)cout<<'1';
	else {cout<<"000";return 0;}
	int a=int(s1[2]),b=int(s2[2]);
	if(a>=65&&b>=65&&a<=67&&b<=67)cout<<'1',p=1;
	else if(a>=68&&b>=68&&a<=70&&b<=70)cout<<'1',p=2;
	else {cout<<"00";return 0;}
	if(p==1){
		if(a==b+1||b==a+1)cout<<'1';
		else cout<<'0';
	}
	else if(p==2){
		if(a==b+2||b==a+2)cout<<'1';
		else cout<<'0';
	}
	return 0;
}
