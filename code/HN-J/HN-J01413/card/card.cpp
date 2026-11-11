#include <bits/stdc++.h>
using namespace std;
#define gc() getchar() 
int read()
{
	int x=0,f=1;
	char c=gc();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(c>='0'&&c<='9') 
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}
void write(int x)
{
	int st[35]={0},top=0,t=0;
	while(x)
	{
		t=x%10;
		st[++top]=t;
		x/=10;
	}
	while(top) putchar(st[top]+'0'),top--;
}
int n,m,a[1000005],dp[1000005],ans,sum,a1[100005],a2[100005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++) if((n-i+1)%2==1) ans++;
		cout<<ans;
	} 
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) a1[i]++;
			else a2[i]++;
			a1[i]+=a1[i-1];
			a2[i]+=a2[i-1]; 
		}
		int aa1=a1[n],aa2=a2[n];
		for(int i=1;i<=n;i++)
		{
			if((aa1-a1[i]+1)%2==1) ans++;
			if((aa2-a2[i]+1)%2==1) sum++;
		}
		cout<<ans<<" "<<sum;             
	} 
	else
	{
		vector<int>v;
		bool vis[100005];
		int b[100005];
		for(int i=1;i<=n;i++)
		{
			while(!v.empty()) v.pop_back();
			memset(vis,0,sizeof vis);
			int m=n-i+1;
			for(int j=m;j<=n;j++)
			{
				if(vis[a[j]])
				{
					while(v.back()!=a[j]) v.pop_back();
					v.pop_back();
					vis[a[j]]=1;
				}
				v.push_back(a[j]);
				vis[a[j]]=1;
			}
			for(int j:v) if(vis[j])b[j]++,vis[j]=0;
		}
		for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	}
	return 0;
}
