#include<bits/stdc++.h> 
using namespace std;
long long a[10000000];
long long n,m,maxx=-1000000;
int sum,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	int l=0,r=maxx,mid;
	while(r>l)
	{
		sum=0;
		mid=(l+r)/2;
		//cout<<"l "<<l<<" r "<<r<<" mid "<<mid<<endl;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<mid)
			{
				
				sum+=(mid-a[i]);
			}
		}
		//cout<<sum<<endl; 
		if(sum==m)
		{
			l=mid;
			break;
		}
		if(sum<m)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
		
		
	}
	for(int i=1;i<=n;i++)
	{
		if(l>=a[i])
		ans++;
	}
	cout<<ans;
	return 0;
}

