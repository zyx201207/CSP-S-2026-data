#include<bits/stdc++.h>//blue
using namespace std;
const int N=6000010;
int c,T,d[N];
long long a[N];
priority_queue<pair<int,int> > q;
int n;
long long D;
long long read()//fast read
{
	char s=getchar();
	long long x=0,y=1;
	if(s=='-')
		y=-1;
	else if(s>='0' && s<='9')
		x=s-'0';
	s=getchar();
	while(s>='0' && s<='9')
	{
		x=x*10+s-'0';
		s=getchar();
	}
	return x*y;
}
bool dijkstra(int s,int e)
{
	memset(d,0x3f,sizeof(d));
	q.push(make_pair(0,s));
	d[s]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		//printf("%d\n",x);
		q.pop();
		//printf("%d\n",x);
		for(int i=x+1;a[i]-a[x]<=D && i<=e;i++)
		{
			if(d[i]>d[x]+1 && a[i]-a[x]<=D)
			{
				d[i]=d[x]+1;
				q.push(make_pair(-d[i],i));
			}
		}
	}
	if(d[e]==0x3f3f3f3f)
		return 0;
	//printf("%d\n",d[e]);
	if(c==11 || c==12)
	{
		int cha=a[2]-a[1];
		if(cha<D && D<2*cha)
			return 0;
	}
	int flag=0;//           !!!
	for(int cnt=1;cnt<d[e];cnt++)
	{
		int sum=0;
		for(int i=e-1;i>=s+1 && a[e]-a[i]<=D;i--)
		{
			if(d[i]==d[e]-cnt)
				sum++;
			if(sum>2)
				return 0;
		}
		if(sum==2)
			flag++;
		if(flag>=2)
			return 0;
	}
	if(!flag)
		return 0;
	//printf("%d %d\n",s,e);
	return 1;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--)
	{
		//memset(a,0,sizeof(a));
		scanf("%d",&n);D=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
			//scanf("%lld",&a[i]);
		if(c==11 || c==12)
		{
			long long cha=a[2]-a[1];
			if(D<cha*2)
			{
				puts("0");
				continue;
			}
			int ans=n-(int(D/cha)*2-1);
			if(ans<0)
				puts("0");
			else
				printf("%d\n",ans);
			continue;
		}
		if(c==13 || c==14)
		{
			int ans=n-3;
			if(ans<=0)
			{
				puts("0");
				continue;
			}
			int res=0;
			for(int i=2;i<n;i++)
			{
				if(a[i]>=a[1]+D && a[i]<=a[n]-D)
				{
					res=i;
					break;
				}
			}
			for(int l=2,r=res+1;r<n && l<res;)
			{
				if(a[r]-a[l]>=2*D)//impossible?
					l++;
				if(a[r]-a[l]<=D)
					r++;
				if(a[r]-a[l]<2*D && a[r]-a[l]>D)
				{
					ans++;
					r++;
					int tr=r;
					while(a[tr]-a[l]<2*D && a[tr]-a[l]>D)
					{
						ans++;
						tr++;
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(dijkstra(i,j))
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}