#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=500010;

int n,m;
int a[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	int cnt=m;
	int sum=0,ans=0;
	int cha=a[2]-a[1];
	
	a[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]+1)
		{
			if(sum+a[i]>cnt)
			{
				ans=i;
				break;
			}
			
			else
			{
				sum+=a[i];
			}
		}
		
		else if(a[i]-a[i-1]==cha)
		{
			if(m%2!=0)
			{
				ans=ceil(m/cha);
			}
			
			else
			{
				ans=ceil(m/cha);
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}