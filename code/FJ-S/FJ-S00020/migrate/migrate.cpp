// zhu CCF de shu ju shui rang wo fan xiang gua fen
//T3 n^2 56
//QAQ bie gua le a
#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e6+10;
long long a[N];
int l[N],r[N];
int dp[N],num[N],dpnum[N],sum[N],num2[N];
long long rd()
{
	int f=1;
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar(); 
	}
	return x*f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			a[i]=rd();
			if(i>1)
			{
				if(a[i]-a[i-1]!=a[2]-a[1])
				{
					flag=0;
				}
			}
		}
		if(flag==1&&c>10)
		{
			long long s=(d/(a[2]-a[1]));
			if(s==0||s==1)
			{
				printf("0\n");
				continue;
			}
			s=s*2-1;
			long long ans=n-s;
			ans=max(ans,0ll);
			printf("%lld\n",ans);
			continue; 
		}
		int j=1;
		for(int i=1;i<=n;i++)
		{
			while(a[j+1]-a[i]<=d&&j<n)
			{
				j++;
			}
			r[i]=j;
		}
		j=n;
		for(int i=n;i>=1;i--)
		{
			while(a[i]-a[j-1]<=d&&j>1)
			{
				j--;
			}
			l[i]=j;
		}
		int ID=0;
		for(int i=1;i<=n;i++)
		{
			if(l[i]==1&&r[i]==n)
			{
				ID=i;
				break;
			}
		}
		if(ID!=0&&c>10)
		{
			for(int i=1;i<=n;i++)
			{
				num2[i]=0;
			}
			for(int i=1;i<=n;i++)
			{
				num2[l[i]]++;
			}
			long long ans=0;
			for(int i=1;i<ID;i++)
			{
				ans+=num2[r[i]-1];
			}
			printf("%lld\n",ans);
			continue;
		}
//		printf("?\n");
//		continue;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				num[j]=0;
				dpnum[j]=0;
				dp[j]=0;
			}
			dp[i]=0;
			dpnum[i]=1;
			sum[i-1]=0;
			sum[i]=1;
			num[0]=i;
			for(int j=i+1;j<=n;j++)
			{
				int k=l[j];
				if(k<=i)
				{
					k=i;
				}
				dp[j]=dp[k]+1;
				dpnum[j]=sum[num[dp[k]]]-sum[k-1];
//				cout<<sum[num[dp[k]]]<<' '<<k-1<<endl;
				if(dpnum[j]>5)
				{
					dpnum[j]=5;
				}		
				sum[j]=sum[j-1]+dpnum[j];
				num[dp[j]]=j;
				if(dpnum[j]==2)
				{
					ans++;
				}
//				cout<<"dpnum["<<i<<"]["<<j<<"]="<<dpnum[j]<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
