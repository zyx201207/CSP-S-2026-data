#include<bits/stdc++.h>
#define Code using
#define by namespace
#define wjb std
Code by wjb;
#define int long long
int in()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
const int N=2e6+10;
int a[N],dp[N][2],n,d,pre[N];
int las(int i){return pre[i];}
int f(int s)
{
	for(int i=s;i<=n;i++)dp[i][0]=dp[i][1]=0;
	dp[s][0]=1;
	for(int i=s+1;i<=n;i++)
	{
		int j=las(i);
		if(j<s){dp[i][0]=1;continue;}
		if(j+1<i)
		{
			if(max(las(j+1),s)==j)dp[i][0]|=dp[j][0],dp[i][1]|=dp[j][1];
			else
			{
				if(!dp[j+1][0])dp[i][0]|=dp[j][0];
				if(!dp[j+1][1])dp[i][1]|=dp[j][1];
			}
			if(max(las(j),s)==j)continue;
			if(max(las(j+1),s)==j)continue;
			if(j+2>=i)dp[i][1]|=dp[j+1][0];
			else if(!dp[j+2][0])dp[i][1]|=dp[j+1][0];
		}
		else dp[i][0]|=dp[j][0],dp[i][1]|=dp[j][1];
	}
//	for(int i=s;i<=n;i++)
//	{
//		cerr<<s<<" "<<i<<" 0 : "<<dp[i][0]<<" #\n";
//		cerr<<s<<" "<<i<<" 1 : "<<dp[i][1]<<" #\n";
//	}
	int res=0;
	for(int i=s+1;i<=n;i++)res+=dp[i][1];
	return res;
}
void work()
{
	n=in(),d=in();int ans=0;
	for(int i=1;i<=n;i++)a[i]=in();
//	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1,j=1;i<=n;i++)
	{
		while(a[i]-a[j]>d)j++;
		pre[i]=j;
	}
	for(int i=1;i<=n;i++)ans+=f(i);
	out(ans),putchar('\n');
}
void work2()
{
	n=in(),d=in();
	for(int i=1;i<=n;i++)a[i]=in();
	if(n==1)return out(0),putchar('\n'),void();
	int x=a[2]-a[1];
	int cnt=d/x;
	if(cnt<=1)return out(0),putchar('\n'),void();
	int res=cnt+cnt-1;
	out(max(0ll,n-res)),putchar('\n');
}
signed main()
{
//	system("fc migrate4.ans migrate.out");return 0;
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	int c=in();
	if(c==11||c==12)for(int t=in();t--;work2());
	else for(int t=in();t--;work());
	return 0;
}
/*
0 1
7 663
-1000 -558 -116 105 326 547 989
*/
