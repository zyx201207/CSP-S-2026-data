#include<bits/stdc++.h>
using namespace std;
string st1,st11,st2,st22,st;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>st1>>st11>>st2>>st22;
	if((st1[0]=='0' && st1[0]=='1') || (st1[0]=='1' && st1[1]=='7'))
	{
		cout<<0000;
		return 0;
	}
	if((st2[0]=='0' && st2[0]=='1') || (st2[0]=='1' && st2[1]=='7'))
	{
		cout<<0000;
		return 0;
	}
	bool f=1;
	if(f==1 && st1==st2) cout<<1;
	else cout<<0,f=0;
	if(f==1 && st11[0]==st22[0] && st11[1]==st22[1]) cout<<1;
	else cout<<0,f=0;
	if(st11[2]<st22[2]) swap(st11,st22);
	if(f==1 && (st11[2]<='C' && st22[2]<='C') || (st11[2]>='D' && st22[2]>='D')) cout<<1;
	else cout<<0,f=0;
	if(f==1 && (st11[2]<='C' && st22[2]<='C' && st11[2]==char(st22[2]+1)) || (st11[2]>='D' && st22[2]>='D' && st11[2]=='D' && st22[2]=='F')) cout<<1;
	else cout<<0,f=0;
	return 0;
}
