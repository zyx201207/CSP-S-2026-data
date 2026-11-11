#include<cstdio>
#include<bitset>
using std::bitset;
bitset<33>num[200010];
int nt[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		int max=0;
		for(int i=1;i<=n;i++)
		{
			int s;
			scanf("%d",&s);
			max=(max>s?max:s);
		}
		printf("%d",max);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int s;
		scanf("%d",&s);
		nt[i]=i+1;
		num[i]=s;
	}
	nt[0]=1;
	nt[n]=-1;
	long long ans=0;
	for(int i=30;i>=0&&n>=m;i--)
	{
		int cur=nt[0],cnt=0;
		while(cur!=-1&&n>=m)
		{
			cnt+=num[cur][i];
			cur=nt[cur];
		}
		ans<<=1;
		ans+=(cnt>=m);
		if(cnt<m)continue;
		while(nt[0]!=-1&&(!num[nt[0]][i])&&n>=m)nt[0]=nt[nt[0]];
		cur=nt[0];
		if(cur==-1)break;
		while(cur!=-1&&nt[cur]!=-1&&n>=m)
		{
			while(nt[cur]!=-1&&(!num[nt[cur]][i])&&n>=m)nt[cur]=nt[nt[cur]],n--;//hao rong chang
			cur=nt[cur];
		}
	}
	printf("%lld",ans);
	return 0;
}
