#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n,m,a[500005],ans=-(1e18+5),pre[500005],p2[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n>500)
	{
		for(ll i=1;i<=n;i++) p2[i]=0;
		for(ll i=1;i<=n;i++)
		{
			ll ss=pre[i-1]+(i-1-p2[i-1])*(a[i]-a[i-1]);
			p2[i]=p2[i-1];
			if(ss<=m&&ss>=0) 
			{ 
				pre[i]=ss;
				ans=max(ans,i-p2[i-1]);
			}
			else
			{
				int k=p2[i-1];
				while(ss>m) 
				{
					ss=ss-(a[i]-a[k]);
					k++;
				}
				if(ss<0)
				{
					k=i-1;
					ss=0;
				}
				p2[i]=k;
				ans=max(ans,i-k);
				pre[i]=ss;
			}
			
		} 
		
	}
	else{
		
		for(int i=1;i<=n;i++)
		{
			ll kk=1,sum=0;
			for(int j=i-1;j>=1;j--)
			{
				if(sum+a[i]-a[j]<=m) 
				{
					kk++;
					sum+=a[i]-a[j];
				}
			}
			ans=max(ans,kk);
		}
		
	}
	cout<<ans;
	return 0;
}
