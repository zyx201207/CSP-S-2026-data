#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=5;i++)ans[i]=1;
	int c1,c2,sn1,sn2,ss1,ss2;
	char s1[5],s2[5];cin>>c1>>s1>>c2>>s2;
	sn1=(s1[0]-'0')*10+(s1[1]-'0');
	sn2=(s2[0]-'0')*10+(s2[1]-'0');
	ss1=s1[2]-'A'+1;ss2=s2[2]-'A'+1;
	if(c1!=c2)ans[1]=0,ans[2]=0,ans[3]=0,ans[4]=0;
	if(sn1!=sn2)ans[2]=0,ans[3]=0,ans[4]=0;
	if(ss1==1||ss1==2||ss1==3)
	{
		if(ss2==4||ss2==5)ans[3]=0,ans[4]=0;
	}
	else
	{
		if(ss2==1||ss2==2||ss2==3)ans[3]=0,ans[4]=0;
	}
	if((ss1==1&&ss2==3)||(ss1==3&&ss2==1))ans[4]=0;
	for(int i=1;i<=4;i++)printf("%d",ans[i]);
	return 0;
}
