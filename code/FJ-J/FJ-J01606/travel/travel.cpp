//祝__wanghc__、__NightDay__、chen_14514、void_ghost、EternalArcana CSP rp++

//9:05签到成功! rp+=INT_MAX! 

//~ 但是，hc似乎是今年最蒻的那个... ~ 

#include<bits/stdc++.h>
using namespace std;
#define write ios::sync_with_stdio(false);
#define by cin.tie(0);
#define __wanghc__ cout.tie(0);

inline bool check1(string a,string b)
{
	return (a[2]=='A' && b[2]=='B') || (a[2]=='A' && b[2]=='C') || (a[2]=='B' && b[2]=='C') 
	|| (a[2]=='B' && b[2]=='A') || (a[2]=='C' && b[2]=='A') || (a[2]=='C' && b[2]=='A') 
	|| (a[2]=='D' && b[2]=='F') || (a[2]=='F' && b[2]=='D');
}

inline bool check2(string a,string b)
{	
	if((a[2]=='C' && b[2]=='D') || (a[2]=='D' && b[2]=='C')) return 0;
	return (abs(stoi(a.substr(0,2))-stoi(b.substr(0,2)))==1 && abs((a[2]-'0')-(b[2]-'0'))==0) || 
	(abs(stoi(a.substr(0,2))-stoi(b.substr(0,2)))==0 && abs((a[2]-'0')-(b[2]-'0'))==1);
}

int main()
{
	write by __wanghc__
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string r1,x1,r2,x2;
	cin>>r1>>r2>>x1>>x2;
	
	int ck1,ck2,ck3,ck4;
	ck1=ck2=ck3=ck4=0;
	
	if(r1==x1) ck1=1;
	if(ck1 && r2.substr(0,2)==x2.substr(0,2))
		ck2=1;
	if(ck2 && check1(r2,x2)) ck3=1;
	if(ck1 && check2(r2,x2)) ck4=1;
	
	cout<<ck1<<ck2<<ck3<<ck4;
	return 0;
}

//Trick or treat!
