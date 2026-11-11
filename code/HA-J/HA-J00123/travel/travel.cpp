#include<bits/stdc++.h>
using namespace std;
bool flag1[5]={0,0,0,1,1},flag2[4];
char s1[4],s2[4];
int c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %s %d %s",&c1,s1,&c2,s2);
	flag2[0]=c1==c2;
	flag2[1]=flag2[0]&&s1[0]==s2[0]&&s1[1]==s2[1];
	flag2[2]=flag2[1]&&flag1[s1[2]-65]==flag1[s2[2]-65];
	flag2[3]=flag2[2]&&abs(s1[2]-s2[2])==1;
	printf("%d%d%d%d",flag2[0],flag2[1],flag2[2],flag2[3]);
	return 0;
}
