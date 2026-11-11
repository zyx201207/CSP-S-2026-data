#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
vector <int>q;
long long f[300005];
long long ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag =1;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1 && a[i]<a[i-1]) flag = 0; 
	}
	if(flag)
	{
		for(int i = 1;i<n;i++)
		{
			if(a[i]!=a[i+1]) cout<<i<<" ";
		}
		cout<<n;
	}
	else
	{
		for(long long i = 1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(long long j = i;j<=n;j++)
		{
			
			if(f[a[j]] == 1)
			{
				int s = j-1;
				while(a[s] !=a[j])
				{
					q.pop_back();
					f[a[s]] = 0;
					s-=1;		
				}
			}
			else 
			{
				q.push_back(a[j]);
				f[a[j]] = 1;	
			}	
			
		}
		
		while(!q.empty())
		{
			ans[q.back()]+=1;
			q.pop_back();
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	}
	
	return 0;
}

