#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+5;
int a[N],t[N],ans[N];
signed main()
{
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(ans,0,sizeof(ans));
		for(int j=i;j<=n;j++)
		{
			int f=-1;
			for(int k=i;k<=j-1;k++)
			{
				if(a[k]==a[j])
				{
					f=k;
					break;
				}
			}
			if(f==-1) ans[a[j]]++;
			else {
				for(int k=f;k<=j;k++) ans[a[k]]--;
				ans[a[j]]++;
			}
		}
		for(int j=1;j<=maxn;j++)
		{
			if(ans[j]>0) t[j]++;
		}
	}
	for(int i=1;i<=maxn;i++) if(t[i]!=0) cout<<t[i]<<" ";
	return 0;
}
