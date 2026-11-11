#include<bits/stdc++.h>
using namespace std;
char a[2],a1[3],a2[2],a3[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>a2>>a3;
	for(int i=0;i<2;i++)
	{
		if(a[i]!=a2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<2;i++)
	{
		if(a1[i]!=a3[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if((a1[2]<=67 and a3[2]<=67) or (a1[2]>67 and a3[2]>67)) cout<<"1";
	else {cout<<"00";return 0;}
	if(abs(a1[2]-a3[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
