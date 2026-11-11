#include<bits/stdc++.h>
using namespace std;
const int N=510;
int m,n,a[N];
map<int,int> mp[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vector<int> vt;
		for(int j=i;j<=n;j++)
		{
			bool flag=0;
			for(unsigned int k=0;k<vt.size();k++)
			{
				if(vt[k]==a[j]) flag=1;
				if(flag) vt.pop_back();
			}
			vt.push_back(a[j]);
		}
		for(unsigned int j=0;j<vt.size();j++)
		{
			mp[i][vt[j]]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			ans+=mp[j][i];
		}
		cout<<ans<<" ";
	}
	return 0;
}
