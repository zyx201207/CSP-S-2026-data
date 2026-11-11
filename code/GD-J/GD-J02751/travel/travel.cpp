#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int ans[4]={0};
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s[101];
	for(int i=1;i<=13;i++)
		cin>>s[i];
	if(s[1]==s[6]&&s[2]==s[7])
	{	ans[0]=1;
		if(s[3]==s[8]&&s[4]==s[9])
		{	ans[1]=1;
			if(s[5]<='C'&&s[5]>='A'&&s[10]<='C'&&s[10]>='A')
			{	ans[2]=1;
				if(int(s[5])+1==int(s[10])||int(s[5])-1==int(s[10]))
					ans[3]=1;
			}
			else if((s[5]=='D'&&s[10]=='F')||(s[5]=='F'&&s[10]=='D'))
				ans[2]=1,ans[3]=1;
		}
	}
	for(int i=0;i<4;i++)
		cout<<ans[i];
	cout<<"\n";
	return 0;
}
//10. 考生不能在注释中写侮辱性话语、歌词、诗词、散文等与考试无关的话语，若有违反可能会收到取消成绩或以上处分。I Love CCF!
