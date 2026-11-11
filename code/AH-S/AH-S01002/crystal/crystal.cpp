#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
LL a[N],b[N],s[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	unsigned long long m;
	int zd=0;
	bool p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=i) p=1;
	}
	if(p==1)
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			unsigned long long m1=m;
			int ans=0;
			memset(b,0,sizeof(b));
			for(int j=1;j<=n;j++)
			{
				b[j]=a[i]-a[j];
			}
			sort(b+1,b+n+1);
			for(int j=1;j<=n;j++)
			{
				if(b[j]<0) continue;
				if(m1-b[j]<0) break;
				ans++;
				m1-=b[j];
			}
			zd=max(zd,ans);
			if(m1<=0) break;
		}
		cout<<zd;
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;i++)
		{
			if(s[i]<=m) ans=i;
		}
		cout<<ans+1;
	}
	return 0;
}

