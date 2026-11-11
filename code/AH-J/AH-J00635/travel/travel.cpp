#include<bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
int ans[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		ans[1]=1;
	if(s[0]==ss[0]&&s[1]==ss[1])
	{
		ans[2]=1;
		if(s[2]>='A'&&ss[2]>='A'&&s[2]<='C'&&ss[2]<='C')
		{
			ans[3]=1;
			if(abs(s[2]-ss[2])==1)
			ans[4]=1;
		}
		else if(s[2]>='D'&&ss[2]>='D'&&s[2]<='F'&&ss[2]<='F')
		{
			ans[3]=1;
			if(abs(s[2]-ss[2])==1)
			ans[4]=1;
		}
		else
		{
			ans[3]=0;
			ans[4]=0;
		}
	}
	}
	for(int i=1;i<=4;i++)
	cout<<ans[i];
	return 0;
}
