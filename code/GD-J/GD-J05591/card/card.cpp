#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[200005];
int ok[200005];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(ok,0,sizeof(ok));
		vector<int>mp;
		int sz=0;
		for(int j=i+1;j<=n;j++)
		{
			int x=a[j];
			if(!ok[x])
			{
				ok[x]=1;
				mp.push_back(x);
				sz++;
			}
			else
			{
				while(1)
				{
					if(mp[sz]!=x)
					{
						sz--;
						ok[sz]=0;
						mp.pop_back();
					}
					else break;
				}
			}
		}
		for(int x:mp)
		{
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
