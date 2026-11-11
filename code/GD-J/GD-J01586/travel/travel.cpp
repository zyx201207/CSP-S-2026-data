#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	freopen(travel.in,'r',stdin);
	freopen(travel.out,'w',stdout);
	string c1,c2,c3,c4;
	int shu,shu2,p;
	cin>>c1>>c2>>c3>>c4;
	if(c1[0]=='1' && c1[1]=='6') return 0;
	else if(c1[0]=='0' && c1[1]=='1') return 0;
	if(c3[0]=='1' && c3[1]=='6') return 0;
	else if(c3[0]=='0' && c3[1]=='1') return 0;
	if(c1[0]==c3[0] && c1[1]==c3[1]) cout<<1;
	else cout<<0;
	if(c2[0]==c4[0] && c2[1]==c4[1])
	{
		cout<<1;
		p=1;
	}
	else
	{
		cout<<0;
		p=0;
	}
	if(c2[2]=='A' || c2[2]=='B' || c2[2]=='C') shu=1;
	else if(c2[2]=='D' || c2[2]=='F') shu=2;
	if(c4[2]=='A' || c4[2]=='B' || c4[2]=='C') shu2=1;
	else if(c4[2]=='D' || c4[2]=='F') shu2=2;
	if(shu==shu2 && p==1)
	{
		cout<<1;
	}
	else cout<<0;
	if(shu==1 && shu2==1)
	{
		if(c2[2]=='A' && c4[2]=='B') cout<<1;
		else if(c2[2]=='B' && c4[2]=='C') cout<<1;
		else if(c4[2]=='A' && c2[2]=='B') cout<<1;
		else if(c4[2]=='B' && c2[2]=='C') cout<<1;
		else cout<<0;
	}
	else if(shu==2 && shu2==2)
	{
		if(c2[2]=='D' && c4[2]=='F') cout<<1;
		else if(c2[2]=='F' && c4[2]=='D') cout<<1;
		else cout<<0;
	}
	else cout<<0;
} 
