#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
		{x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=5e5+7;
const int M=3e5+7;
int n,m;
int top=0;
int c[N];
int cnt[M],s[N],cnt2[M],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j;
	memset(cnt,0,sizeof cnt);
	memset(cnt2,0,sizeof cnt2);
	memset(ans,0,sizeof ans);
	n=read();m=read();
	for(i=1;i<=n;i++)
	{
		c[i]=read();
		cnt[c[i]]++;
	}
	for(i=n;i;i--)
	{
		/*for(j=1;j<=m;j++)
			printf("%d ",ans[j]);
		printf("\n");
		for(j=1;j<=m;j++)
			printf("%d ",cnt2[j]);
		printf("\n");*/
		if(!cnt2[c[i]])
		{
			s[++top]=c[i];
			for(j=1;j<=top;j++)
				ans[s[j]]+=cnt[c[i]];
			cnt2[c[i]]=1;
			continue;
		}
		while(top)
			if(s[top--]==c[i])
				break;
		s[++top]=c[i];
	}
	for(i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
