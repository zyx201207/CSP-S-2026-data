#include<bits/stdc++.h>
using namespace std;
int stoi(string s)
{
	int len=s.size();
	int ans=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>'9'||s[i]<'0') break;
		ans=ans*10+(s[i]-'0');
	}
	return ans;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s[4][3];
	for(int i=0;i<4;i++)
		cin>>s[i];
	int s1,s2;
	s1=stoi(s[0]);
	s2=stoi(s[1]);
	int s3,s4;
	s3=stoi(s[2]);
	s4=stoi(s[3]);
	int c1,c2,c3,c4;
	c1=c2=c3=c4=0;
	if(s1==s3) c1=1;
	if(c1&&s2==s4) c2=1;
	if(c1&&c2&&((s[1][2]=='D'&&s[3][2]=='F')||(s[1][2]=='F'&&s[3][2]=='D')||(((s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C')&&(s[3][2]=='A'||s[3][2]=='B'||s[3][2]=='C'))&&s[1][2]!=s[3][2])))
		c3=1;
	if(c1&&c2&&c3&&((s[1][2]=='D'&&s[3][2]=='F')||(s[1][2]=='F'&&s[3][2]=='D')||(s[1][2]=='A'&&s[3][2]=='B')||(s[1][2]=='B'&&s[3][2]=='A')||(s[1][2]=='B'&&s[3][2]=='C')||(s[1][2]=='C'&&s[3][2]=='B')))
		c4=1;
	printf("%d%d%d%d",c1,c2,c3,c4);
	fclose(stdin);
	fclose(stdout);
	return 0;
}//Accepted on 9:11
//想起来去年我同桌(去年的HN-J00087)写了个playgon 最后在木棍这道题上拿了棍木 
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout); 
//如果有人做迷惑行为大赏 
//我应该能诈到你 
//这时监考老师问 
//饶沐萱来了没有 
//我才意识到 
//我和Moya_Rao奆佬一个考场 
