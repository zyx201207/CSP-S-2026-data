#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define N 200005
struct Item
{
	int num;
	char c;
};
Item s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		char c;
		scanf("%d %c",&a,&c);
		s[i].num=a,s[i].c=c;
	}
	long long ans=0;
	for(int i=0,k=n-1;i<=k;)
	{
		if(s[i].c!=s[k].c)
		{
			if(s[i].num<s[k].num)
			{
				s[k].num-=s[i].num,ans+=s[i].num,s[i].num=0;
				i++;
			}
			else
			{
				s[i].num-=s[k].num,ans+=s[k].num,s[k].num=0;
				k--;
			}
		}
		else
		{
			if(s[i].num<s[k].num)
			{
				s[k].num-=s[i].num,s[i].num=0;
				i++;
			}
			else
			{
				s[i].num-=s[k].num,s[k].num=0;
				k--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
