#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,ans[4];
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ans[0]=0;ans[1]=0;ans[2]=0;ans[3]=0;
	if(c1==c2)
	{
		ans[0]=1;
	}
	if(ans[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		ans[1]=1;
	}
	if(s1[2]-'0'-67>=0)
	{
		a=1;
	}
	if(s2[2]-'0'-67>=0)
	{
		b=1;
	}
	if(ans[0]==1&&ans[1]==1&&a==b)
	{
		ans[2]=1;
		if(abs((s1[2]-'0'-65)-(s2[2]-'0'-65))==1)
		{
			ans[3]=1;
		}
	}
	for(int i=0;i<4;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
