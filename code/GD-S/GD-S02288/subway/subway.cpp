#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e4+5;
ll c,n,m,d,q,w[maxn],b[maxn];
struct node
{
	ll num,a[maxn],t[maxn];
}k[maxn];
ll finder(ll ki,ll id)
{
	for(int j=1;j<=k[ki].num;j++)
	{
		if(k[ki].a[j]==id)
		{
			return j;
		}
	}
	return -1;
}
ll find(ll x)
{
	ll sum=0;
	 for(int i=1;i<=n;i++)
	 {
	 	if(finder(i,x)!=-1) sum++;
	}
	cout<<sum;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].num;
		for(int j=1;j<=k[i].num;j++)
		{
			cin>>k[i].a[j]>>k[i].t[j];
			b[k[i].a[j]]++;
		}
	}
	while(q--)
	{
		ll x,y,sum=0,ans=0,mx=0;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int i=1;i<=n;i++)
		{
			sum=0;
			ll flag=find(x);
			if(flag==-1) continue;
			sum+=a[flag];
			for(int j=1;j<=n;j++)
			{
				for(int ki=1;ki<=n;ki++)
				{
					if(find(k,j)!=-1) sum+=k[ki].a[j];
				}
			}
			mx=max(mx,sum);
		}
		cout<<ans+mx<<endl;
	}
	return 0;
} 
