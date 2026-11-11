#include<bits/stdc++.h>
using namespace std;
long long n,ind,lastnum;
long long sum,ans;
struct node
{
	long long len;
	char g;
}str[200005];
long long last;
char lastc=' ';
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i = 1;i <= n;i++)
	{
		long long num;
		char c;
		scanf("%d %c",&num,&c);
		sum+=num;
		if(c!=lastc)
		{
			str[ind].len=lastnum;
			str[ind].g=lastc;
			ind++;
			lastnum=num;
			lastc=c;
		}
		else
		{
			lastnum+=num;
		}
	}
	str[ind].len=lastnum;
	str[ind].g=lastc;
	if(ind ==1)
	{
		cout << 0;
		return 0;
	}
	long long pos1=1,pos2=ind,num1=0,num2=0;
	n=sum/2;
	last=0;
	char lastc=' ';
	while(num1+str[pos1].len<=n)
	{
		long long need=str[pos1].len;
		num1+=need;
		printf("");
		if(last>=need)
		{
			ans+=need*(str[pos1].g!=lastc);
			last-=need;
			pos1++;
			continue;
		}
		else
		{
			ans+=last*(str[pos1].g!=lastc);
			need-=last;
			last=0;
		}
		num2=0;
		while(num2+str[pos2].len<=need)
		{
			num2+=str[pos2].len;
			if(str[pos2].g!=str[pos1].g)
			{
				ans+=str[pos2].len;
			}
			pos2--;
		}
		if(num2<need)
		{
			ans+=(need-num2)*(str[pos2].g!=str[pos1].g);
			last=num2+str[pos2].len-need;
			lastc=str[pos2].g;
			pos2--;
		}
		pos1++;
	}
	if(num1<n)
	{
		int need=n-num1;
		if(last>=need)
		{
			ans+=need*(str[pos1].g!=lastc);
			last-=need;
		}
		else
		{
			ans+=last*(str[pos1].g!=lastc);
			need-=last;
			last=0;
		}
		while(num2+str[pos2].len<=need)
		{
			num2+=str[pos2].len;
			if(str[pos2].g!=str[pos1].g)
			{
				ans+=str[pos2].len;
			}
			pos2--;
		}
		if(num2<need)
		{
			ans+=(need-num2)*(str[pos2].g!=str[pos1].g);
		}
	}
	printf("%lld",ans);
	return 0;
}
