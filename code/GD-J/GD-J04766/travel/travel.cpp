#include<bits/stdc++.h>
using namespace std;
//const int N=
string c1,c2,c3,c4;
bool pd=0,pdd=0,pddd=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
	{
		pddd=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(pddd==1 && c2.substr(0,2)==c4.substr(0,2))
	{
		pdd=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(pdd==1 && (c2[2]<='C' && c4[2]<='C') || (c2[2]>='D' && c2[2]<='F' && c4[2]>='D' && c4[2]<='F'))
	{
		pd=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(pd==1 && ((char(c2[2]+1)==c4[2] && c2[2]!='C' && c4[2]!='D') || ((char(c2[2]-1)==c4[2] && c2[2]!='D' && c4[2]!='C'))))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
