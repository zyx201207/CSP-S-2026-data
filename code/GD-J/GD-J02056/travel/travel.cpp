#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,cc1,cc2,ss1,ss2;
string c1,s1,c2,s2;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cc1=(c1[0]-'0')*10+c1[1]-'0';
	cc2=(c2[0]-'0')*10+c2[1]-'0';
	a=s1[2],b=s2[2];
	ss1=(s1[0]-'0')*10+s1[1]-'0';
	ss2=(s2[0]-'0')*10+s2[1]-'0';
	if(cc1==cc2)
	{
		ans=8;
		if(ss1==ss2)
		{
			ans=12;
			if(a=='F'&&b=='D') ans=15;
			else if(a-'A'<=2&&b-'A'<=2)
			{
				ans=14;
				if(abs(a-b)==1) ans=15;
			}
		}
	}
	for(int i=3;i>=0;i--)
	{
		if(ans&(1<<i)) cout<<1;
		else cout<<0; 
	}
	return 0; 
}
