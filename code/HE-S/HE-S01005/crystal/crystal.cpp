#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N=5e5+10;
int n;
LL m;
LL q[N];
LL d[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	int p=m;
	for(int i=0;i<n;i++) scanf("%lld",&q[i]);
	
	sort(q,q+n);
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		d[i]=q[i+1]-q[i];
		if(d[i]==0) cnt++;
	}
	if(n<=5000)
	{
		int res=-1,k=0;
		for(int z=0;z<n;z++)
		{
			m=p,k=0;
			for(int i=z,j=z;i<n;i++)
			{
				while(j<i)
				{
					while(q[j]<q[i])
					{
						q[j]++;
						m--;
						if(m<=0&&q[j]<q[i])
						{
							res=max(res,i-z);
							k=1;
							break;
						}
						else if(q[j]==q[i]&&j==i-1)
						{
							int u=i,ans=0;
							while(q[u++]==q[j+1]) ans++;
							res=max(res,i+ans-z);
							if(m<d[i]*(i-z)) k=1;
							break;
						}
					}
					j++;
					if(j==i||k==1) break;
				}
				j=z;
				if(k==1)
				{
					m==-1;
					break;
				}
			}
		}
		if(cnt==n-1||m==0) printf("%d",cnt+1);
		else printf("%d",res);
	}
	else
	{
		for(int i=0,j=0;i<n;i++)
		{
			while(j<i)
			{
				while(q[j]<q[i])
				{
					q[j]++;
					m--;
					if(m<=0&&q[j]<q[i])
					{
						printf("%lld",i);
						break;
					}
					else if(m<=0&&q[j]==q[i]&&j==i-1)
					{
						int u=i,ans=0;
						while(q[u++]==q[j+1]) ans++;
						printf("%lld",i+ans);
						break;
					}
				}
				j++;
				if(j==i||m<=0) break;
			}
			j=0;
			if(m<=0) break;
		}
	}
	
	return 0;
}
