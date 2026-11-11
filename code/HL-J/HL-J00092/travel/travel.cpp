#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans1=0,ans2=0,ans3=0,ans4=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a==c)
	{
		ans1=1;
	}
	
	string a1=b.substr(0,2);
	string a2=d.substr(0,2);
	if (a1==a2 && ans1)
	{
		ans2=1;
	}
	
	char q=b[2];
	char p=d[2];
	int p1=0,q1=0;
	if (p=='A' || p=='B' || p=='C')
	{
		p1=1;
	}
	if (p=='D' || p=='F')
	{
		p1=2;
	}
	if (q=='A' || q=='B' || q=='C')
	{
		q1=1;
	}
	if (q=='D' || q=='F')
	{
		q1=2;
	}
	if (ans1 && ans2 && p1==q1)
	{
		ans3=1;
	}
	
	if (ans1 && ans2 && ans3==1 && p1==1)
	{
		if ((p=='A' && q=='B') || (p=='B' && q=='A') || (p=='B' && q=='C') || (p=='C' && q=='B'))
		{
			ans4=1;
		}
	}
	else if (ans1 && ans2 && ans3==1 && p1==2)
	{
		if ((p=='D' && q=='F') || (p=='F' && q=='D'))
		{
			ans4=1;
		}
	} 
	
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
