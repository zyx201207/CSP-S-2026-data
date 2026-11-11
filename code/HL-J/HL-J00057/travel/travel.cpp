#include<bits/stdc++.h>
using namespace std;
int t(string s)
{
	if(s[0]=='A'||s[0]=='B'||s[0]=='C') return 1;
	else if(s[0]=='D'||s[0]=='F') return 2;
}
int x(string s)
{
	if(s[0]=='A') return 1;
	if(s[0]=='B') return 2;
	if(s[0]=='C') return 3;
	if(s[0]=='D') return 4;
	if(s[0]=='E') return 5;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string a1,b1,sa,sb,s;
	cin>>a1>>sa>>b1>>sb;
	//a1 chexiang b1 chexiang
	//pa paihao pb paihao p2a zuoweibianhao p2b zuoweibianhao
	string pa,pb,p2a,p2b;
	pa+=sa[0];pa+=sa[1];
	pb+=sb[0];pb+=sb[1];
	p2a+=sa[2];p2b+=sb[2];
	if(a1==b1)
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	if((a1==b1)&&(pa==pb))
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	if((a1==b1)&&(pa==pb)&&(t(p2a)==t(p2b)))
	{
		s+='1';
	} 
	else
	{
		s+='0';
	}
	//t,guodao,x,xianglinchazhi
	if((a1==b1)&&(pa==pb)&&(t(p2a)==t(p2b))&&(abs(x(p2a)-x(p2b))==1)) 
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	cout<<s<<'\n';
	return 0;
}
