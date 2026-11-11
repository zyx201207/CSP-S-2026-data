#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool a=1,b=1,c=1,d=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	
	char a1=s1[0],a2=s1[1],a5=s1[2];
	char a3=s2[0],a4=s2[1],a6=s2[2];
	string f1="",f2="";
	f1+=a1;f1+=a2;
	f2+=a3;f2+=a4;
	
	if(c1!=c2)
	{
		a=b=c=d=0;
	}else if(f1!=f2)
	{
	    b=c=d=0;	
	}else if((a5=='A'||a5=='B'||a5=='C')&&(a6=='D'||a6=='F') || (a6=='A'||a6=='B'||a6=='C')&&(a5=='D'||a5=='F'))
	{
		c=d=0;
	}else if(abs(a5-a6)!=1)
	{
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
