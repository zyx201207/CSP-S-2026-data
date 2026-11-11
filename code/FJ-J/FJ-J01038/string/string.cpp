#include<bits/stdc++.h>
using namespace std;
struct stru{long long num;char c;}a[200025];
long long n,i,j,k,ans=0,len=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		long long nm;char ch;
		scanf("%lld %c",&nm,&ch);
		if(ch==a[len].c)a[len].num+=nm;
		else
		{
			++len;
			a[len].num=nm,a[len].c=ch;
		}
	}
	i=1,j=len;
	while(i<j)
	{
		while(a[i].num<=0)i++;
		while(a[j].num<=0)j--;
		if(a[i].num>=a[j].num)
		{
			ans+=a[j].num;
			a[i].num-=a[j].num;
			j--;
		}
		else{
			ans+=a[i].num;
			a[j].num-=a[i].num;
			i++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
