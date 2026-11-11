#include <bits/stdc++.h>
using namespace std;

const long long MAXN=5e5+10;
long long a[MAXN],ans[MAXN],pos[MAXN],t[MAXN],id;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)
	{
		//serialize
		memset(pos,-1,sizeof(pos));
		id=0;
		//start game
		for(long long j=i;j<=n;j++)
		{
			long long k=a[j];
			if(pos[k]!=-1) //exist
			{
				for(long long cc=pos[k];cc<=id;cc++)
				{
					pos[t[cc]]=-1;
					t[cc]=0;
				}
			}
			t[++id]=k; //right
			pos[k]=id;
		}
		//end game
		for(long long j=1;j<=id;j++)
			ans[t[j]]++;
	}
	for(long long i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}