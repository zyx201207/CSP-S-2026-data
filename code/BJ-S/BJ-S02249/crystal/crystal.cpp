#include <bits/stdc++.h>//qiu AC!
using namespace std;
const int Nmax=5e5+7;
int a[Nmax];
int n;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=m;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt==0)
		{
			break;
		}
		else if(a[i]<a[i+1]&&cnt>=0)
		{
			for(int j=1;j<=i;j++)
			{
				if(cnt==0)
				{
					break;
				}
				if(cnt-(a[i+1]-a[j])>=0)
				{
					cnt-=a[i+1]-a[j];
					a[j]=a[i+1];
				}
				else 
				{
					cnt=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[1])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}