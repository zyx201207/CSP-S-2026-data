#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,ans=0,cun[N],f[N];
long long m,a[N],b[N];
bool ok=false;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int u=0;
	a[0]=1e12+5;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			u++;
			cun[u]=1;
		}
		else
		{
			ok=true;
			cun[u]++;
		}
		b[u]=a[i];
		f[i]=u;
	}
	if(ok)
	{
		for(int i=1;i<=u;i++)
		{
			long long now=m;
			int j=i-1;
			int cnt=cun[i];
			while(j>=1&&now>0)
			{
				long long cha=b[i]-b[j];
				if(now>=cha*cun[j])
				{
					now-=cha*cun[j];
					cnt+=cun[j];
				}
				else
				{
					int x=now/cha;
					now-=x*cha;
					cnt+=x;
				}
				j--;
			}
			ans=max(cnt,ans);	
		}
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			long long nn=0;
			nn=(a[n]-a[i]+1)*(n-i)/2;
			if(nn<=m)
			{
				ans=n-i+1;
			}
			else
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
 } 
