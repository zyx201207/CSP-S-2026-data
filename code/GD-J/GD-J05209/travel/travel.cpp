#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(int(s1[2])<=67&&int(s2[2])<=67) cout<<1;
	else if(int(s1[2])>67&&int(s2[2])>67) cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	if(int(s1[2])+1==int(s2[2])||int(s1[2])-1==int(s2[2])) cout<<1;
	else cout<<0;
	return 0;
}
