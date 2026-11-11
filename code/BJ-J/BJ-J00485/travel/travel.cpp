#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aa,bb;
	cin>>a>>b>>aa>>bb;
	int f=0;
	for(int i=0;i<=1;i++)
	{
		if(a[i]!=aa[i]) f=1;
	}
	if(f==0) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	int ff=0;
	for(int i=0;i<=1;i++)
	{
		if(b[i]!=bb[i]) ff=1;
	}
	if(ff==0) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A' && (bb[2]=='B' || bb[2]=='C') || b[2]=='B' && (bb[2]=='A' || bb[2]=='C') || b[2]=='C' && (bb[2]=='A' || bb[2]=='B') || b[2]=='D' && bb[2]=='F' || b[2]=='F' && bb[2]=='D')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(b[2]=='A' && bb[2]=='B' || b[2]=='B' && bb[2]=='A' || b[2]=='B' && bb[2]=='C' || b[2]=='C' && bb[2]=='B' || b[2]=='D' && bb[2]=='F' || b[2]=='F' && bb[2]=='D')
	{
		cout<<1;
	}
	else cout<<"0";
	return 0;
}
