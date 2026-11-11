#include <bits/stdc++.h>
using namespace std;
int n,xb;
long long m,a[500005],minc=1e12,ans=1;
bool flagb=true,flagc=true;

bool cmp(long long a,long long b)
{
	return a<b;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int mid=(a[1]+a[n])/2;
	for(int i=1;i<=n;i++)
	{
		if(minc>abs(mid-a[i]))
		{
			minc=mid-a[i];
			xb=i;
		}
	}
	int b=xb-1,c=xb+1;
	while(m>=0 && (flagb || flagc))
	{
		if(flagb && flagc)
		{
			if(a[xb]-a[b]<a[c]-a[xb])
			{
				m-=a[xb]-a[b];
				if(m>=0)
				{
					ans++;
				}
				if(b>1) b--;
				else flagb=false;
			}
			else
			{
				m-=a[c]-a[xb];
				if(m>=0)
				{
					ans++;
				}
				if(c<n) c++;
				else flagc=false;
			}
		}
		else if(flagb)
		{
			m-=a[xb]-a[b];
			if(m>=0) ans++;
		}
		else if(flagc)
		{
			m-=a[c]-a[xb];
			if(m>=0) ans++;
		}
	}
	cout<<ans;
	return 0;
}

