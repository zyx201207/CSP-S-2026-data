#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=(int)(2e6+10);
int a[MAXN],summ[MAXN];
int dp[MAXN],minn[MAXN];
inline int read()
{
	char c=' ';
	while(1)
	{
		c=getchar();
		if(c=='-' or (c>='0' and c<='9'))break;
	}
	int f=1,num=0;
	if(c=='-')f=-1;
	else num=(c-'0');
	while(1)
	{
		c=getchar();
		if(c<'0' or c>'9')break;
		num=num*10+(c-'0');
	}
	return num*f;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//Çë¿ªfreopen
	int c=read(),t=read();
	if(c==11 or c==12)
	{
		while(t--)
		{
			int n=read(),d=read();
			//cout<<n<<" "<<d<<endl;
			int maxn=-1;
			for(int i=1;i<=n;i++)
			{
				a[i]=read();
				//if(i==2)cout<<a[i]-a[1]<<endl;
				if(i>1 and a[i]-a[1]<=d)maxn=i;
			}
			if(maxn<=2)cout<<0<<endl;
			else
			{
				maxn=maxn*2-2;
				cout<<max(0ll,n-maxn+1)<<endl;
			}
		}
		return 0;
	}
	while(t--)
	{
		int n=read(),d=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=1;
			summ[i-1]=0;
			summ[i]=1;
			minn[i]=0;
			int l=i,wei=i;
			for(int j=i+1;j<=n;j++)
			{
				minn[j]=INT_MAX;
				while(a[j]-a[l]>d)++l;
				if(l==j)break;
				while(minn[wei+1]<=minn[l])wei++;
				//cout<<"j:"<<j<<" "<<l<<" "<<wei<<endl;
				minn[j]=minn[l]+1;
				dp[j]=summ[wei]-summ[l-1];
				summ[j]=summ[j-1]+dp[j];
				//cout<<dp[j]<<endl;
				if(dp[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6

