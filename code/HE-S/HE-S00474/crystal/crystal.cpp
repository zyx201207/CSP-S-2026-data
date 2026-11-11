#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int mi=1e17;
int ma=-1e17;
int ans=0;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ss=-777,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(ss==-777&&i!=1)ss=a[i]-a[i-1],cnt++;
		else if(ss!=-777)
		{
			if(a[i]-a[i-1]==ss)cnt++;
		}	
		mi=min(a[i],mi);
		ma=max(ma,a[i]);
	}
	if(cnt==n-1)
	{
			int l=1,r=n,mid;
			while(l<=r)
			{
				mid=l+r>>1;
				if(((n-mid)*ss+ss)*(n-mid)/2<=m)r=mid-1;
				else l=mid+1;
			}
			cout<<n-l+1;

		return 0;
	}

	sort(a+1,a+1+n);
	for(int val=mi;val<=ma;val++)
	{
		int id=upper_bound(a+1,a+1+n,val)-a;
		int mm=m,sum=0;
		while(1)
		{
			if(id==0)break;
			if(mm==0)break;
			if(a[id]<=val)
			{
				if(val-a[id]>mm)break;
				mm-=(val-a[id]);
				sum++;
			}
			id--;
		}
		ans=max(ans,sum);
		
	}
	cout<<ans;
	return 0;
}
