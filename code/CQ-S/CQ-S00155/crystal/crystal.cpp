#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int n,m,a[N];
int sum[N],res[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		sum[i]=a[i+1]-a[i];
	}
	for(int i=n-1;i>=1;i--)
	{
		res[i]=res[i+1]+sum[i];
	}
	queue<int>q;
	int maxn=-0x3f3f3f3f;
	int ans=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		q.push(res[i]);
//		cout<<q.size()<<'\n';
		ans+=res[i];
		if((ans-res[i+1]*(q.size()))>m)
		{
//			cout<<ans<<' '<<res[i+1]*(q.size())<<'\n';
			while(!q.empty())
			{
				ans-=q.front();
				
				q.pop();
				if(ans-res[i+1]*(q.size())<m)
				{
					break;
				}
			}
		}
		int len=q.size();
		maxn=max(maxn,len);
	}
	cout<<maxn+1;
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
