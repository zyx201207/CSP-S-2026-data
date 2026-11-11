#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int rp;
int main()
{
/*	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp++;
	rp+=INF;
	*/
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	//shu ru
	if(s1==s3) cout<<1;
	else if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	//che xiang
	int p1=0,p2=0;
	for(int i=0;i<=1;i++) p1=p1*10+s2[i]-48,p2=p2*10+s4[i]-48;//hang
	if(p1==p2) cout<<1;
	else if(p1!=p2)
	{
		cout<<"000";
		return 0;
	}
	//tong hang
	if(s2[2]=='F'||s2[2]=='D')
	{
		if(s4[2]=='F'||s4[2]=='D') 
		{
			cout<<11;
			return 0;
		}
		else if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')
		{
			cout<<"00";
			return 0;
		}
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C') cout<<1;
		else if(s4[2]=='F'||s4[2]=='D')
		{
			cout<<"00";
			return 0;
		}
	}
	//tong ce
	if(s2[2]=='B'||s4[2]=='B') cout<<1;
	else cout<<0;
	return 0;
}
