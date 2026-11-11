#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1500009];
int sum[1500009];

bool check(int x,int r)//Ҫȡx 
{
	int totba=sum[r]-sum[x-1];
	int delta=a[r]*(r-x+1)-totba;
	if(delta<=m)return true;
	else return false;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	
	int ans=0,ansid=0;
	
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int cnt=0,id=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid,i))
			{
				cnt=i-mid+1;
				id=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		
//		cout<<a[i]<<' '<<cnt<<'\n';
		
		if(cnt>ans)ansid=id;
		
		ans=max(ans,cnt);
	}
	
	cout<<ans;
	
//	cout<<' '<<ansid;
	
	return 0; 
}
