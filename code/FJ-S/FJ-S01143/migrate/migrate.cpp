#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int id,T,n;
long long d,x[N],ans,cnt[N][3],posl[N],posr[N];
int Cnt,num[N];
void init()
{
	for(int i=1;i<=n;i++)
	  posl[i]=posr[i]=cnt[i][0]=cnt[i][1]=cnt[i][2]=0;
	ans=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&id,&T);
	while(T--)
	{
		init();
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1,j=0;i<=n;i++)
		{
			while(j<n&&x[j+1]-x[i]<=d) j++;
			posr[i]=j;
		}
		for(int i=n,j=n+1;i>=1;i--)
		{
			while(j>1&&x[i]-x[j-1]<=d) j--;
			posl[i]=j;
		}
		if(n>300)
		{
			for(int i=1;i<=n;i++)
			{
				long long p=posl[i],P=posl[p];
				long long f1=(posr[p]==i),f2=(i-p>1),f3=(i-p>1&&posr[p+1]==i),f4=(posr[P]==p+1&&P!=p);
				cnt[i][0]=cnt[p][0]*f1+1;
				cnt[i][1]=cnt[p][2]+f2*(cnt[P][0]*f4+(max(posl[p+2],P+1)-max(posl[p+1],P+1)));
				cnt[i][2]=cnt[p][2]+f3*(cnt[P][0]*f4+(max(posl[p+2],P+1)-max(posl[p+1],P+1)));
				ans+=cnt[i][1];
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int st=i,sum=0;
					Cnt=0;
					while(st!=j)
					{
						int lst=st;
						st=min(1ll*j,posr[st]);
						if(st==lst) break;
						num[++Cnt]=st;
					}
					if(st!=j) continue;
					while(st!=i)
					{
						int lst=st;
						st=max(1ll*i,posl[st]);
						if(st==lst) break;
						if(Cnt>1) sum+=num[Cnt-1]-st;
						Cnt--;
					}
					if(st!=i) continue;
					ans+=(sum==1);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
