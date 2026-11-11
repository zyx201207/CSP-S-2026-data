#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2,ans[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[2]-'A';
	a2=s2[2]-'A';
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		ans[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans[2]=1;
			{
				if(a1>=0&&a1<=2&&a2>=0&&a2<=2)
				{
					ans[3]=1;
					if(a1+1==a2||a1-1==a2)
					  ans[4]=1;
				}
				if(a1>=3&&a1<=4&&a2>=3&&a2<=4)
				{
					ans[3]=1;
					if(a1+1==a2||a1-1==a2)
					  ans[4]=1;
				}
			}
		}
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}