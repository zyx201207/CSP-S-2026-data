#include<bits/stdc++.h>
#define int long long
using namespace std;
string c,c_;
char s[4],s_[4];
bool ans[5];
signed main()
{
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
	cin>>c;
	for(int i=1;i<=3;i++)	cin>>s[i];
	cin>>c_;
	for(int j=1;j<=3;j++)	cin>>s_[j];
	for(int i=1;i<=4;i++)	ans[i]=0;
	if(c==c_)
	{
		ans[1]=1;
		if(s[1]==s_[1]&&s[2]==s_[2])
		{
			ans[2]=1;
			if(s[3]=='A'||s[3]=='B'||s[3]=='C')
			{
				if(s_[3]!='D'&&s_[3]!='F')
				{
					ans[3]=1;
					if(s[3]-1==s_[3]||s[3]+1==s_[3])
						ans[4]=1;
				}
			}
			else
			{
				if(s_[3]=='D'&&s_[3]=='F')
				{
					ans[3]=1;
					if(s[3]-1==s_[3]||s[3]+1==s_[3])
						ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
		cout<<ans[i];
   	return 0;
}

