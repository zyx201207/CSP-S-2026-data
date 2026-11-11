#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1;
	string c2,s2;
	bool f1=0,f2=0,f3=0,f4=0;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) f1=1;
	else f1=0;
	
	if(f1==1 && s1[0]==s2[0] && s1[1]==s2[1]) f2=1;
	else f2=0;
	
	if(f1==1 && f2==1 && ((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C'))) f3=1;
	else if(f1==1 && f2==1 && ((s1[2]>='D' && s1[2]<='F') && (s2[2]>='D' && s2[2]<='F'))) f3=1;
	else f3=0;
	
	if(s1[2]=='A' && s2[2]=='B') f4=1;
	else if(f1==1 && f2==1 && f3==1 && ((s1[2]=='B' && s2[2]=='A') || (s1[2]=='B' && s2[2]=='C'))) f4=1;
	else if(f1==1 && f2==1 && f3==1 && (s1[2]=='C' && s2[2]=='B')) f4=1;
	else if(f1==1 && f2==1 && f3==1  && (s1[2]=='D' && s2[2]=='F')) f4=1;
	else if(f1==1 && f2==1 && f3==1 && (s1[2]=='F' && s2[2]=='D')) f4=1;
	else f4=0;
	
	if(f1==1) cout<<1;
	else cout<<0;
	if(f2==1) cout<<1;
	else cout<<0;
	if(f3==1) cout<<1;
	else cout<<0;
	if(f4==1) cout<<1;
	else cout<<0;
	return 0;
}
