#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[4],s2[4];
int ans[4];
char sum[8]={' ','A','B','C',' ','D','F',' '};
bool check2(char x,char y)
{
	int flag1=0,flag2=0;
	for(int i=1;i<=3;i++)
	{
		if(x==sum[i])
		{
			flag1=1;
			break;
		}
		else
		{
			flag1=2;
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(y==sum[i])
		{
			flag2=1;
			break;
		}
		else
		{
			flag2=2;
		}
	}
	if(flag1==flag2)
	{
		return true;
	}
	return false;
}
bool check3(char x,char y)
{
	for(int i=1;i<=6;i++)
	{
		if(x==sum[i])
		{
			if(y==sum[i-1] || y==sum[i+1])
			{
				return true;
			}
		}
	}
	return false;
}
void check()
{
	if(c1==c2)
	{
		ans[0]=1;
		if(s1[1]==s2[1] && s1[2]==s2[2])
		{
			ans[1]=1;
			if(check2(s1[3],s2[3]))
			{
				ans[2]=1;
			}
		}
	}
	if(s1[1]==s2[1] && s1[2]==s2[2])
	{
		if(check3(s1[3],s2[3]))
		{
			ans[3]=1;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	check();
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
