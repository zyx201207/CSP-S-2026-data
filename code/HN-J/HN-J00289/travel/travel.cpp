#include<bits/stdc++.h>
using namespace std;
#define int long long
string rx,rid,xx,xid;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>rid>>xx>>xid;
	if(rx!=xx)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(rid[0]!=xid[0]||rid[1]!=xid[1])
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if((rid[2]>='A'&&rid[2]<='C'&&xid[2]>='D'&&xid[2]<='E')||(xid[2]>='A'&&xid[2]<='C'&&rid[2]>='D'&&rid[2]<='E'))
	{
		cout<<"1100"<<endl;
		return 0;
	}
	if(rid[2]+1==xid[2]||rid[2]-1==xid[2])
	{
		cout<<"1111"<<endl;
		return 0;
	}
	cout<<"1110"<<endl;
	return 0;
 } 
