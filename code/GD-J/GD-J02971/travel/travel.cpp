#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
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
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')) cout<<"11";
	else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')) cout<<"11";
	else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<"11";
	
	else if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')) cout<<"10";
	else cout<<"00";
	return 0;
}
