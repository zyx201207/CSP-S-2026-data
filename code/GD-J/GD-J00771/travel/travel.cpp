#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string cc1,ss1,cc2,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	bool ans1=0,ans2=0,ans3=0,ans4=0;
	if(cc1==cc2)
	{
		ans1=1;
	}
	if(ans1&&ss1[0]==ss2[0]&&ss1[1]==ss2[1])
	{
		ans2=1;
	}
	bool rr1=0,rr2=0;
	if(ss1[2]=='A'||ss1[2]=='B'||ss1[2]=='C')
	{
		rr1=1;
	}
	if(ss2[2]=='A'||ss2[2]=='B'||ss2[2]=='C')
	{
		rr2=1;
	}
	if(ans2&&rr1==rr2)
	{
		ans3=1;
	}
	if(ans3&&abs((ss1[2]-'A')-(ss2[2]-'A'))==1)
	{
		ans4=1;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
