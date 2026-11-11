//GZ-J00452 陈浩铭 弘毅中学 
#include<bits/stdc++.h>
using namespace std;
int zs=0;
char c1[3],s1[4],c2[3],s2[4],ans[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ans[5]='\0';
	cin>>c1>>s1>>c2>>s2;
	
	//两张车票对应的座位是否在同一节车厢//两张车票对应的座位是否在同一节车厢的同一排；
	bool mt=false,mt1=false;
	for(int i=0;i<2;i++)
	{
	if(c1[i]!=c2[i])
	{
		mt=true;
	}
	if(s1[i]!=s2[i])
	{
	mt1=true;	
	}	
	}
	if(mt==false)
	{
		ans[zs]='1';
		zs++;
	}
	else
	{
	ans[zs]='0';
	zs++;	
	}
	if(mt1==false&&mt==false)
	{
		ans[zs]='1';
		zs++;
		//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
		if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
		{
			ans[zs]='1';
			zs++;
			ans[zs]='1';
		}
		else if(((s1[2]=='A'||s1[2]=='B')||s1[2]=='C')&&((s2[2]=='A'||s2[2]=='B')||s2[2]=='C'))
		{
			ans[zs]='1';
			zs++;
			//两张车票对应的座位是否相邻。
			if(s1[2]=='B'||s2[2]=='B') 
			{
				ans[zs]='1';
			}
			else
			{
				ans[zs]='0';
			}
		}
		else{
			ans[zs]='0';
			zs++;
			ans[zs]='0';
		}
	}
	else
	{
	ans[zs]='0';
	zs++;
	ans[zs]='0';
	zs++;
  ans[zs]='0';	
	}
	cout<<ans;
	return 0;
 } 
