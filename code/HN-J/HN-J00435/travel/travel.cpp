#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans[5]={0,0,0,0,0};
	char c1[4]={},s1[4]={},c2[4]={},s2[4]={};
	scanf("%s",c1); 
	scanf("%s",s1);
	scanf("%s",c2);
	scanf("%s",s2);
	if(c1[0]==c2[0])
	{
		if(c1[1]==c2[1])
		ans[1]=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&ans[1]==1)
	{
		ans[2]=1;
	}
	if(s1[2]>='D')
	{
		if(s2[2]>='D')
		{
			if(ans[1]==1&&ans[2]==1)
			ans[3]=1;
			if(s1[2]-s2[2]==2||s2[2]-s1[2]==2)
			{
				 if(ans[1]==1&&ans[2]==1&&ans[3]==1)
				ans[4]=1;
			}
		}
	}
	if(s1[2]<='C')
	{
		if(s2[2]<='C')
		{
			if(ans[1]==1&&ans[2]==1)
			ans[3]=1;
			if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
			if(ans[1]==1&&ans[2]==1&&ans[3]==1)
			ans[4]=1;	
			}
		}
		else
		{
			ans[4]=0;
		}
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	fclose(stdin);
	fclose(stdout);	
} 
