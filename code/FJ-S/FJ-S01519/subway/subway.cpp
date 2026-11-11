#include<bits/stdc++.h>
using namespace std;
const long long INF=1000000000000000;
inline int rd()
{
	int num=0;char ch=getchar();
	while('0'>ch||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		num=(num<<3)+(num<<1)+ch-'0';
		ch=getchar();
	}
	return num;
}
void wrt(long long num)
{
	if(num>9)wrt(num/10);
	putchar(num%10+'0');
	return;
}
int w[500001];
vector<pair<int,int> > a[500001];
long long dp[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1;i<=n;i++)
	{
		int k=rd(),a1,t;
		for(int j=1;j<=k;j++)
		{
			a1=rd(),t=rd();
			a[a1].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=INF;
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=a[i].size();
		for(int j=0;j<len;j++)
			for(int k=0;k<len;k++)
			{
				dp[a[i][j].first][a[i][k].first]
				=min(dp[a[i][j].first][a[i][k].first]
				,(long long)(a[i][j].second+a[i][k].second));
			}	
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	int x,y,len1,len2;
	long long ans;
	for(int i=1;i<=q;i++)
	{
		ans=INF;
		x=rd(),y=rd();
		len1=a[x].size(),len2=a[y].size();
		for(int j=0;j<len1;j++)
			for(int k=0;k<len2;k++)
			{
				ans=min(ans,dp[a[x][j].first][a[y][k].first]
				+w[x]+a[x][j].second+w[y]+a[y][k].second);
			}	
		wrt(ans);
		putchar('\n');
	}
	return 0;
}
