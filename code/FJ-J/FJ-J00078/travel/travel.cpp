#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans1=1;
	else ans1=0;
	int p1=0,p2=0;
	for(int i=0;i<2;i++)
	{
		p1=p1*10+(s1[i]-'0');
		p2=p2*10+(s2[i]-'0');
	}
	if(ans1&&p1==p2)ans2=1;
	else ans2=0;
	char a=s1[2],b=s2[2];
	if(a=='A'&&b=='B'&&ans1&&ans2)ans3=1;
	else if(a=='A'&&b=='C'&&ans1&&ans2)ans3=1;
	else if(a=='B'&&b=='C'&&ans1&&ans2)ans3=1;
	else if(a=='D'&&b=='F'&&ans1&&ans2)ans3=1;
	else if(a=='B'&&b=='A'&&ans1&&ans2)ans3=1;
	else if(a=='C'&&b=='A'&&ans1&&ans2)ans3=1;
	else if(a=='C'&&b=='B'&&ans1&&ans2)ans3=1;
	else if(a=='F'&&b=='D'&&ans1&&ans2)ans3=1;
	else ans3=0;
	if(a=='A'&&b=='B'&&ans1&&ans2&&ans3)ans4=1;
	else if(a=='B'&&b=='C'&&ans1&&ans2&&ans3)ans4=1;
	else if(a=='D'&&b=='F'&&ans1&&ans2&&ans3)ans4=1;
	else if(a=='B'&&b=='A'&&ans1&&ans2&&ans3)ans4=1;
	else if(a=='C'&&b=='B'&&ans1&&ans2&&ans3)ans4=1;
	else if(a=='F'&&b=='D'&&ans1&&ans2&&ans3)ans4=1;
	else ans4=0;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
