#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
long long m,a[500005];
map<long long,int> mp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		if(!mp[x])
		{
			cnt++;
			a[cnt]=x;
		}
		mp[x]++;
	}
	sort(a+1,a+cnt+1);
	int j=0,x=0,dj=0;
	long long lst=0;//j指针 x选的数量 dj即j取了几个 lst之前花了多少
	ans=mp[a[1]];
	j=1,dj=x=mp[a[1]];
	for(int i=2;i<=cnt;i++)
	{
		long long d=a[i]-a[i-1];
		while(1ll*d*x>m-lst && j<i)
		{
			x--;
			dj--;
			lst-=(a[i-1]-a[j]);
			if(dj==0)
			{
				j++;
				dj=mp[a[j]];
			}
		}
		lst+=1ll*d*x;
		x+=mp[a[i]];
		ans=max(ans,x);
		//cout<<j<<" "<<dj<<" "<<x<<" "<<lst<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
