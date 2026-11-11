#include<cstdio>
#include<cmath>
char c_1[5],c_2[5],s_1[5],s_2[5];//车票信息 
int x,y,z,k;//四个问题的答案 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",c_1,s_1,c_2,s_2);
	if(c_1[0]==c_2[0]&&c_1[1]==c_2[1]) x=1;
	if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]&&x==1) y=1;
	if((s_1[2]<'D'&&s_2[2]<'D'&&y==1)||(s_1[2]>'C'&&s_2[2]>'C'&&y==1)) z=1;
	if((s_1[2]>'C'&&s_2[2]>'C'&&z==1)||(abs(s_1[2]-s_2[2])==1&&z==1)) k=1;
	printf("%d%d%d%d",x,y,z,k);
	return 0;
} 
