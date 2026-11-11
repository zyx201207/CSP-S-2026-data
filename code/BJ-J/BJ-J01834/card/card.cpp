#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
	stack<int> s;
	vector<int> ds(m+1,0);
	vector<int> sx(n+1);
	for(int i=1;i<=n;i++) cin>>sx[i];
	for(int i=1;i<=n;i++)
	{
		vector<int> exist(n+1,0);
		vector<pair<int,int>> existt(m+1);
		for(int j=i;j<=n;j++) exist[j]=1;
	///	for(int j=i;j<=n;j++) cout<<cf[j];
	///	cout<<endl;
		for(int j=i;j<=n;j++)
		{
			if(existt[sx[j]].first==1)
			{
	///			if(i==3) cout<<j<<endl;
				for(int o=j-1;o>=existt[sx[j]].second;o--) 
				{
					existt[sx[o]].first=0;
					exist[o]=0;
				}
			}
			existt[sx[j]].second=j;
			existt[sx[j]].first=1;
		}
		for(int j=i;j<=n;j++)
		{
			if(exist[j]) ds[sx[j]]++;
		}
///cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ds[i]<<" ";
	return 0;
///	cout<<sum<<" "<<wz<<endl;


}

