#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e5+10;

int n;

ll m,a[N],f[N],c[N];

inline bool check(int l,int r)
{
	ll d=f[r]-f[l]-(l-1ll)*(c[r]-c[l]);
	return m>=d;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	f[1]=c[1]=f[0]=a[0]=c[0]=0;
	for(int i=2;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
		f[i]=f[i-1]+(i-1ll)*c[i];
		c[i]+=c[i-1];
	}
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i,now=1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid,i))
			{
				r=mid-1;
				now=i-mid+1;
			}
			else
				l=mid+1;
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}



































