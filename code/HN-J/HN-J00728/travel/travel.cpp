#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string lsa,lsb;
	cin>>a1>>lsa>>b1>>lsb;
	if(a1==b1) cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(lsa[0]==lsb[0]&&lsa[1]==lsb[1]) cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if((lsa[2]<='C'&&lsb[2]<='C')||(lsa[2]>'C'&&lsb[2]>'C')) cout<<1;
	else
	{
		cout<<0<<0;
		return 0;
	}
	if(abs(int(lsa[2])-int(lsb[2]))==1) cout<<1;
	else cout<<0; 
	return 0;
}
