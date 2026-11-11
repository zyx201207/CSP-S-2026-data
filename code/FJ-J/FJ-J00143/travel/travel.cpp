#include<iostream>
#include<string>
using namespace std;

bool check1(int p1,int p2,int c1,int c2,char s1,char s2)
{
	if(p1!=p2 || c1!=c2)
		return 0;
	if((s1=='A' || s1=='B' || s1=='C') && (s2=='A' || s2=='B' || s2=='C'))
		return 1;
	else if((s1=='D' || s1=='F') && (s2=='D' || s2=='F'))
		return 1;
	return 0;
}

bool check2(int p1,int p2,int c1,int c2,char s1,char s2)
{
	if(p1!=p2 || c1!=c2)
		return 0;
	if((s1=='A' && s2=='B') || (s1=='C' && s2=='B') || (s1=='B' && s2=='A') || (s1=='B' && s2=='C'))
		return 1;
	else if((s1=='D' && s2=='F') || (s1=='F' && s2=='D'))
		return 1;
	return 0;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int cr=(c1[0]-'0')*10+(c1[1]-'0');
	int cx=(c2[0]-'0')*10+(c2[1]-'0');
	int sr=(s1[0]-'0')*10+(s1[1]-'0');
	int sx=(s2[0]-'0')*10+(s2[1]-'0');
	char kr=s1[2];
	char kx=s2[2];
	
	if(cr==cx) cout<<1;
	else cout<<0;
	
	if(sr==sx && cr==cx) cout<<1;
	else cout<<0;
	
	if(check1(sr,sx,cr,cx,kr,kx)) cout<<1;
	else cout<<0;
	
	if(check2(sr,sx,cr,cx,kr,kx)) cout<<1;
	else cout<<0;
	
	return 0;
}
