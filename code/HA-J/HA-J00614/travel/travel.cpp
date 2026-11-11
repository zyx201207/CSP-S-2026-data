#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w,e,r;
	cin>>q>>w>>e>>r;
	if(q!=e)
	{
		cout<<"0000";
		return 0;
	}
	if(w[0]!=r[0]||w[1]!=r[1])
	{
		cout<<"1000";
		return 0;
	}
	if((w[2]=='C'&&r[2]=='D')||(w[2]=='D'&&r[2]=='C'))
	{
		cout<<"1100";
		return 0;
	}
	if(abs(w[2]-r[2])==2)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
