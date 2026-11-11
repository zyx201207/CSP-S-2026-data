#include<bits/stdc++.h>
using namespace std;	
int a,b,lena,lenb,x,a2,b2,as,bs;
string a1,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>a1>>b>>b1;
	lena=a1.size();
	lenb=b1.size();
	as=int(a1[lena-1]);
	bs=int(b1[lenb-1]);
	for(int i=0;i<lena;i++)
	{
		x=0;
		x=int(a1[i])-48;
		if(0<=x && x<=9)
		{
			a2+=x;
		}
	}
	for(int i=0;i<lenb;i++)
	{
		x=0;
		x=int(b1[i])-48;
		if(0<=x && x<=9)
		{
			b2+=x;
		}
	}
	if(a==b)
	{
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2==b2)
	{
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(65<= as && as<=67 && 65<=bs && bs <=67 )
	{
		cout<<1;
	}else if(68<=as && as <=70 && 68<=bs && bs <=70)
	{
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(as-bs)==1)
	{
		cout<<1;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
