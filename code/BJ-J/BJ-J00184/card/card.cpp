#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<long long> ans(m+1);
	for(int t=1;t<=n;t++)
	{
		vector<bool> isVisit(m+1,false);
		for(int i=t;i<=n;i++)
		{
			if(isVisit[a[i]])
			{
				for(int j=i-1;;j--)
				{
					if(a[j]==a[i])
						break;
					//cout<<"f";
					isVisit[a[j]]=false;
				}
			}
			isVisit[a[i]]=true;
		}
		for(int i=1;i<=m;i++)
			ans[i]+=isVisit[i];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
