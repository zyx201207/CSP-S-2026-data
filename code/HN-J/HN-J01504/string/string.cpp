#include<bits/stdc++.h>
using namespace std;
int n=0;
int a[200010]={0};
char c[200010]={'\0'};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int head=1,tail=n;
	long long hs=0,ts=0,ans=0;
	while(head<tail)
	{
		if(a[head]<a[tail])
		{
			a[tail]-=a[head];
			if(c[head]!=c[tail])ans+=a[head];
			head++;if(!a[tail])tail--;
		}
		else
		{
			a[head]-=a[tail];
			if(c[head]!=c[tail])ans+=a[tail];
			tail--;if(!a[head])head++;
		}
	}
	cout<<ans;
	
	return 0;
}
//每次看两边的时候两边都消掉最短的字母块，做法就是a减掉消的长度，注意要判断哪个字母块短一些，然后一次性全消了 
