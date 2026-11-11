#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],de[500005],kx[500005],prek[500005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int _=0-a[1];
	for(int i=1;i<=n;i++)
		a[i]+=_;
	for(int i=1;i<=n;i++)
		de[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)
	{
		kx[i]=(i-1)*de[i];
		prek[i]=prek[i-1]+kx[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(prek[i]<=m)
			ans=i;
		else break;
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				prek[j]=prek[j]-a[j]+a[i];
			}
			if(prek[i+1]>m) continue;
			int cnt=i+1;
			for(int j=i+1;j<=n;j++)
			{
				if(prek[j]<=m)
					cnt=j;
				else break;
			}
			ans=max(ans,cnt-i);
		}
	}
	else
	{
		vector<int>pre(n+5);
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+a[i];
		for(int i=1;i<=n;i++)
		{
			if(pre[i]<=m)
				ans=i;
			else break;
		}
	}
	
	cout<<ans;
	return 0;
}
//~ int l=i+1,r=n;
//~ while(l<=r)
			//~ {
				//~ cout<<1<<" ";
				//~ int mid=(l+r)/2;
				//~ if(prek[mid]==m)
				//~ {
					//~ if(prek[mid+1]>prek[mid])
					//~ {
						//~ cnt=mid;
						//~ break;
					//~ }
					//~ else
					//~ {
						//~ l=mid+1;
						//~ continue;
					//~ }
				//~ }
				//~ if(prek[mid]>m)
				//~ {
					//~ r=mid;
					//~ continue;
				//~ }
				//~ if(prek[mid]<m)
				//~ {
					//~ cnt=mid;
					//~ if(prek[mid+1]>m) break;
					//~ l=mid;
					//~ continue;
				//~ }
			//~ }
