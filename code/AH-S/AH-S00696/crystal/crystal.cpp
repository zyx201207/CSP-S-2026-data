#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[500005],sum[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ff=1,tt=0;
	for(int i=1;i<=n;i++)
	{
		t[i]=a[i]-a[i-1];
		if(i!=1&&t[i]!=t[2]) ff=0;
		sum[i]=sum[i-1]+a[i];
	}
	if(ff==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(m>(i*t[2]))
			{
				m-=(i*t[2]);
				ans++;
			}
		}
		ans++;
		cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		long long l=1,r=l+i-1,minn=INT_MAX;
		while(r<=n)
		{
			long long cnt=0;
			for(int j=l;j<=r;j++)
			{
				cnt=cnt+(t[j]*(j-l));
			}
			l++;
			r=l+i-1;
			minn=min(minn,cnt);
			
			
			
			//cout<<i<<" "<<cnt<<endl;
		}
		
		
		if(minn<=m)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
