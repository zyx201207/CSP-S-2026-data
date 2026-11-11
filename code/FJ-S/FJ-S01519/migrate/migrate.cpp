#include<bits/stdc++.h>
using namespace std;
inline long long rd()
{
	long long num=0,f=1;char ch=getchar();
	while(('0'>ch||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		num=(num<<3)+(num<<1)+ch-'0';
		ch=getchar();
	}
	return num*f;
}
long long x[2000001];
int dp[2000001][2];
int ls[2000001];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=rd(),T=rd();
	if(c==11||c==12)
	{
		while(T--)
	{
		int n=rd();
		long long d=rd();
		ans=0;
		for(int i=1;i<=n;i++)x[i]=rd();
		int l=1;
		for(int i=1;i<=n;i++)
		{
			while(x[i]-x[l]>d)l++;
			ls[i]=l;
		}
		for(int i=1;i<2;i++)
		{
//			cout<<"from "<<i<<" to somewhere:"<<'\n';
			for(int j=i;j<=n;j++)
			{
				dp[j][0]=0;dp[j][1]=0;
				ls[j]=max(ls[j],i);
			}
			dp[i][1]=1;
			for(int j=i+1;j<=n;j++)
			{
				if(j==ls[j])break;
				int b=dp[ls[j]][1];
				if(ls[j]+2<j&&dp[ls[j]+2][0]==dp[ls[j]][0])b+=dp[ls[j]+2][1];
				if(ls[j]+1<j&&dp[ls[j]+1][0]==dp[ls[j]][0])b+=dp[ls[j]+1][1];
				dp[j][0]=dp[ls[j]][0]+1;
				dp[j][1]=((b>3)?3:b);
//				cout<<dp[j][0]<<' '<<dp[j][1]<<'\n';
				if(dp[j][1]==2)
				{
//					cout<<i<<' '<<j<<'\n';
					ans+=n-j+1;
				}
			}
		}
		printf("%lld\n",ans);
	}
		return 0;
	}
	while(T--)
	{
//		cout<<"----------------------\n";
		ans=0;
		int n=rd();
		long long d=rd();
		for(int i=1;i<=n;i++)x[i]=rd();
		int l=1;
		for(int i=1;i<=n;i++)
		{
			while(x[i]-x[l]>d)l++;
			ls[i]=l;
		}
		for(int i=1;i<n;i++)
		{
//			cout<<"from "<<i<<" to somewhere:"<<'\n';
			for(int j=i;j<=n;j++)
			{
				dp[j][0]=0;dp[j][1]=0;
				ls[j]=max(ls[j],i);
			}
			dp[i][1]=1;
			for(int j=i+1;j<=n;j++)
			{
				if(j==ls[j])break;
				int b=dp[ls[j]][1];
				if(ls[j]+2<j&&dp[ls[j]+2][0]==dp[ls[j]][0])b+=dp[ls[j]+2][1];
				if(ls[j]+1<j&&dp[ls[j]+1][0]==dp[ls[j]][0])b+=dp[ls[j]+1][1];
				dp[j][0]=dp[ls[j]][0]+1;
				dp[j][1]=((b>3)?3:b);
//				cout<<dp[j][0]<<' '<<dp[j][1]<<'\n';
				if(dp[j][1]==2)
				{
//					cout<<i<<' '<<j<<'\n';
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
