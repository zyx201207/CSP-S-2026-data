#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,M; cin>>n>>M;
	int m=M;
	if(n<=5000)
	{
		int a[n+1]={};
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
		}
		int maxx=0;
		for(int k=1;k<=n;k++)
		{
			m=M;
			int b[n+1]={};
			for(int i=1;i<=n;i++) 
			{
				if(a[k]-a[i]>=0)
				{
					b[i]=a[k]-a[i];
				}
				else
				{
					b[i]=LLONG_MAX;
				}
			}
			sort(b+1,b+n+1);
			int cnt=1;
			/*cout<<endl<<k<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<b[i]<<" ";
			}
			cout<<endl;*/
			for(int i=2;i<=n;i++)
			{
				if(b[i]<=m && b[i]>=0)
				{
					m-=b[i];
					cnt++;
					//cout<<m<<" ";;
				}
				else break;
			}
			//cout<<endl;
			maxx=max(maxx,cnt);
			//cout<<k<<" "<<cnt<<endl;
		}
		cout<<maxx;
	}
	else if(m<=1000000000)
	{
		int a[n+1]={};
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int k=a[n/2];
		for(int i=1;i<=n;i++) a[i]=k-a[i];
		sort(a+1,a+n+1,greater<int>());
		int cnt=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<=m && a[i]>=0)
			{
				m-=a[i];
				cnt++;
			}
			else break;
		}
		cout<<cnt;
	}
	else
	{
		int a[n+1]={};
		for(int i=1;i<=n;i++) cin>>a[i];
		int k=a[n];
		for(int i=1;i<=n;i++) a[i]=k-a[i];
		int cnt=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<=m && a[i]>=0)
			{
				m-=a[i];
				cnt++;
			}
			else break;
		}
		cout<<cnt;
	}
	return 0;
}
