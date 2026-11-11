#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using pii=pair<int,int>;
const int N = 5e5+10;
int n,m,a[N],num=0,maxx=-INF,flag;
map<int,int>mp;
int s[N],txt=0,ans=0,len;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(i==1) continue;
		num=a[i];
		txt=m; ans=0;
		memset(s,0,sizeof s);
		for(int j=1;j<=n;j++)
		{
			s[j]=a[j]-num;
		}
		for(int j=i-1;j>=1;j--)
		{
			if(s[j]==0) continue;
			if(s[j]<0 && txt-abs(s[j])>=0)
			{
				txt-=abs(s[j]);
				s[j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0) ans++; 
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx;
	return 0;
} 
