#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,pu,lans;
	cin>>n>>m;
	vector <long long> a,ans,derta;
	for (int i=0;i<n;i++)
	{
		cin>>pu;
		a.push_back(pu);
	}
	for (int i=0;i<n;i++)
	{
		derta.clear();
		lans=0;
		for (int j=0;j<i;j++)
		{
			pu=a[i]-a[j];
			if (pu>=0)
			{
				derta.push_back(pu);
			}
		}
		sort(derta.begin(),derta.end());
		pu=0;
		for (int j=0;j<derta.size();j++)
		{
			if ((derta[j]+pu)<=m)
			{
				pu+=derta[j];
				lans++;
			}
		}
		ans.push_back(lans);
	}
	sort(ans.begin(),ans.end());
	cout<<(ans[ans.size()-1])+1<<endl;
	return 0;
} 
