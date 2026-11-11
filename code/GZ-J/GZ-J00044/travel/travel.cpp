//GZ-J00044 贵州市花溪区实验中学 游梓一
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool k[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		k[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			k[1]=1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				{
					k[2]=1;
					if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
						k[3]=1;
				}
			}
			else
			{
				if(s1[2]=='D'||s1[2]=='F')
				{
					if(s2[2]=='D'||s2[2]=='F')
					{
						k[2]==1;
						k[3]==1;
					}
				}
			}
			
		}
	}
	cout<<k[0]<<k[1]<<k[2]<<k[3];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
