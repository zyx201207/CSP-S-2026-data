#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500050;
int n;
ll m,a[N];
vector<ll > num;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool flag=true;//special:a[i]=i
	ll x=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=x)
			flag=false;
	}
	if(flag)
	{	
		int ans=1;
		for(int i=1;i<=n/2;i++)
		{
			bool flag2=true;
			if(m>=i*x*2)
			{
				if((n%2!=0)||(n%2==0&&i*x<n/2))
				{
					flag2=false;
					m-=i*x*2;
					ans+=2;
				}
			}
			if(m>=i*x&&flag2)
			{
				ans++;
				break;
					
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&a[i]==a[i-1])
			continue;
		for(int j=1;j<=n;j++)
			num.push_back(max(a[i]-a[j],a[j]-a[i]));
		sort(num.begin(),num.end());
		ll cishu=m;
		int ans2=0;
		for(int j=0;j<n;j++)
		{
			if(cishu>=num[j])
			{
				cishu-=num[j];
				ans2++;
			}
		}
		ans=max(ans,ans2);
		num.clear();
	}
	cout<<ans;
	return 0;
}
