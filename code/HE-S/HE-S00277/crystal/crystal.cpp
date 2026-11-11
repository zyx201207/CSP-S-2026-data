#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],m,c[N],ans;
map<int,int> mp;
int main()
{
	//while(1) rp++;
	freopen("cystal.in","r",stdin);
	freopen("cystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			c[i-1]=a[i]-a[i-1];
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=i*c[i];
			if(sum>m)
			{
				cout<<i-1<<endl;
				return 0; 
			}
		}
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		int sum=0,cnt=mp[a[i]];
		for(int j=i-1;j>=1;j--)
		{
			if(sum+a[i]-a[j]>m) break;
			if(a[j]==a[i]) continue;
			sum+=a[i]-a[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
} 
