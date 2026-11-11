#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	int u=s1[2],v=s2[2];
	if('A'<=u&&u<='C'&&'A'<=v&&v<='C') cout<<1;
	else if((u=='D'&&v=='F')||(u=='F'&&v=='D')) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((u=='D'&&v=='F')||(u=='F'&&v=='D'))
	{
		cout<<1;
		return 0;
	}
	else if(abs(u-v)==1) cout<<1;
	else cout<<0;
	return 0;
}
