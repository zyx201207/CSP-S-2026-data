#include<bits/stdc++.h>
#define int long long
using namespace std;
string n,m,a,b;
int get(char c)
{
	if(c<='C')return 0;
	return 1;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n!=m)
	{
		cout<<"0000";
		return 0;
	}
	if(a[0]!=b[0]||a[1]!=b[1])
	{
		cout<<"1000";
		return 0;
	}
	if(get(a[2])!=get(b[2]))
	{
		cout<<"1100";
		return 0;
	}
	if(abs(a[2]-b[2])==1||(a[2]=='F'&&b[2]=='D')||(a[2]=='D'&&b[2]=='F'))
	{
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
//diff
