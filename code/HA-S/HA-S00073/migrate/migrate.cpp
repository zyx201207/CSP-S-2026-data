#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define int __int128
const int N=1e6,A=1e18;
int c,t,n,d,a[N],ans,s[5001][5001],sum[5001][5001];
signed main()
{
	freopen("migrate.in","r",stdin);
	//freopen(".out","r",stdin);
	//freopen(".in","w",stdout);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=10)
		{
			ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					s[i][j]=(i==j?0:(llabs(a[i]-a[j])<=d?1:A)),sum[i][j]=1;
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						if(i==k||j==k||i==j)continue;
						else if(s[i][k]+s[k][j]<s[i][j]){s[i][j]=s[i][k]+s[k][j];sum[i][j]=1;}
						else if(s[i][k]+s[k][j]==s[i][j]){sum[i][j]++;}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ans+=(i==j?0:(sum[i][j]==2?1:0));
			cout<<ans/2<<"\n";
		}
		else cout<<n*(n-1)/2<<"\n";
	}
	return 0;
}
/*
（居然有中文输入法！！） 
迷惑行为诱捕器： 
freopen("r","migrat.out",std);
游记：
14:30 开考
14:37 会T1了
14:59 T1过大样例
15:07 开T2
15:17 T2好难
15:29 补队，T2好简单
15:47 被常数卡成1.5s了
16:23 卡了半个小时的常，无进展，放弃了 
16:24 Google小恐龙，耍起
预计100+(80,100]+0+0=(180,200] 
*/
