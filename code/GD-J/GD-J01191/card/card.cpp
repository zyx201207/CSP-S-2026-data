#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans[N];
long long a[N];

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long x=1;
	for(int i=1;i<=n;i++)
	{
		map<int,int>v;
		for(int j=x;j<=n;j++)
		{
			if(v[a[j]]>=1)
				for(int k=j-1;k>v[a[j]];k--)
				{
					v[a[k]]=0;
					//cout<<"Q"<<a[k]<<" ";
				}
			v[a[j]]=j;
			//cout<<a[j]<<" ";
		}
		//cout<<"\n";
		for(int j=1;j<=m;j++)
			if(v[j]>=1)
				ans[j]++;
		x++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	
	return 0;
 } 
