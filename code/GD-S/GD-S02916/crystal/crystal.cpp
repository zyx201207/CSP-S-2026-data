#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
long long a[N],dp[N],ct[N];
int n,tp;
long long m,ans=-1;
bool f1=1,f2=1;
struct node
{
	int v,cnt;
	bool operator<(const node &x)const {return v<x.v;}
}b[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) f1=0;
		if(i>2&&a[i-1]*2!=a[i]+a[i-2]) f2=0;
	}
	b[++tp].v=a[1],b[tp].cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=b[tp].v) b[++tp].v=a[i],b[tp].cnt=1;
		else b[tp].cnt++;
	}
	sort(b+1,b+1+tp);
	if(f1)
	{
		long long len=0;
		while(len*(len+1)/2ll<=m) len++;
		cout<<len<<'\n';
		return 0;
	}
	else if(f2)
	{
		long long len=0,d=a[2]-a[1];
		while(len*(len+1)/2ll*d<=m) len++;
		cout<<len<<'\n';
		return 0;
	}
	for(int i=tp;i>=1;i--)
	{
		for(int j=i+1;j<=tp;j++)
		{
			if((b[j].v-b[i].v)*b[i].cnt<=(m-dp[j])) dp[j]+=(b[j].v-b[i].v)*b[i].cnt,ct[j]+=b[i].cnt;
			else
			{
				int de=(m-dp[j])/(b[j].v-b[i].v);
				dp[j]+=de*(b[j].v-b[i].v);
				ct[j]+=de;
			}
		}
	}
	for(int i=1;i<=tp;i++) ans=max(ans,ct[i]+b[i].cnt);
	cout<<ans;
}
