#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;

	bool ans1=0,ans2=0,ans3=0,ans4=0;
	if(c==cc)
	{
		ans1=1;
		if(s.substr(0,2)==ss.substr(0,2))
		{
			ans2=1;
			int x,y;
			x=s[2]-'A'+1;
			y=ss[2]-'A'+1;
			if(y==6)
				y=5;
			if((1<=x&&x<=3&&1<=y&&y<=3)||
				(4<=x&&x<=5&&4<=y&&y<=5))
			{
				ans3=1;
				if(abs(x-y)==1)
					ans4=1;
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}