#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a[50001],n,m;
	cin>>n>>m;
	bool b[50001]={0};
	int ans[50001]={0};
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		long long s=a[i];
		if(b[a[i]]==0) b[s]=1;
		else
		{
			int x=i-1;
			while(a[x]==a[i])
			{
				a[x]=-1;
			}
			b[a[i]]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1) ans[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]>0) cout<<ans[i]<<" ";
	}
	return 0;
}

