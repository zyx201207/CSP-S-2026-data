#include<bits/stdc++.h>
using namespace std;
int ri,xi;
string r,x; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ri>>r>>xi>>x;
	if(ri==xi) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(r[0]==x[0]&&r[1]==x[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(((r[2]<='C'&&r[2]>='A')&&(x[2]<='C'&&x[2]>='A'))||((r[2]<='F'&&r[2]>='D')&&(x[2]<='F'&&x[2]>='D'))) cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(r[2]==x[2]+1||r[2]==x[2]-1) cout<<"1";
	else cout<<"0";
	return 0;
} 
