#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll c,t,n,d,a[2000006],ans=0,dif[4000005];

bool check(int l,int r)
{
	if(a[r]-a[l]<=d) return true;
	return false;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) dif[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++)
		{
			if(!check(i,i+1)) continue;
			int l=i,r=n;
			while(l<r-1)
			{
				int mid=(l+r)>>1;
				if(check(i,mid)) l=mid;
				else r=mid-1;
			}
			if(check(i,r)) l=r;
			if(i!=l-1)
			{
				dif[i*2]++;
				dif[l*2-1]--;
			}
			
		}
		ll sum=0;
		for(int i=1;i<=2*n;i++)
		{
			sum+=dif[i];
			if(sum==2) ans++;
		} 
		cout<<ans<<'\n';
	}
	return 0;
}
