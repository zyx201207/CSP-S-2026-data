#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];

bool check(int x,int i)
{
	int k=(i-x+1)*a[i];
	int w=sum[i]-sum[x-1];
	if(w+m>=k) return 1;
	else return 0;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	//	cout<<sum[i]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
	//	cout<<i<<endl;
		while(l<r)
		{
			int mid=(l+r)/2;
	//		cout<<l<<" "<<r<<" "<<mid<<endl;
			if(check(mid,i))
			{
				r=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,(i-r+1));
	}
	cout<<ans;
}
/*
5 8
-3 -1 2 2 7
*/
