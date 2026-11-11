#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans1=2,ans2=2,ans3=2,ans4=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans1=1;
	else ans1=ans2=ans3=ans4=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&ans1!=0) ans2=1;
	else ans2=0;
	if(s1[2]=='A'&&s2[2]=='B'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=1;
	}
	else if(s1[2]=='A'&&s2[2]=='C'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=0;
	}
	else if(s1[2]=='A'&&s2[2]=='D'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='A'&&s2[2]=='F'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='B'&&s2[2]=='A'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=1;
	}
	else if(s1[2]=='B'&&s2[2]=='C'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=1;
	}
	else if(s1[2]=='B'&&s2[2]=='D'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='B'&&s2[2]=='F'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='C'&&s2[2]=='A'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=0;
	}
	else if(s1[2]=='C'&&s2[2]=='B'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=1;
	}
	else if(s1[2]=='C'&&s2[2]=='D'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='C'&&s2[2]=='F'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='D'&&s2[2]=='A'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='D'&&s2[2]=='B'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='D'&&s2[2]=='C'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='D'&&s2[2]=='F'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=1;
	}
	else if(s1[2]=='F'&&s2[2]=='A'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='F'&&s2[2]=='B'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='F'&&s2[2]=='C'&&ans3==2&&ans2!=0)
	{
		ans3=0;
		ans4=0;
	}
	else if(s1[2]=='F'&&s2[2]=='D'&&ans3==2&&ans2!=0)
	{
		ans3=1;
		ans4=1;
	}
	else ans3=ans4=0;
	cout<<ans1<<ans2<<ans3<<ans4;
}
