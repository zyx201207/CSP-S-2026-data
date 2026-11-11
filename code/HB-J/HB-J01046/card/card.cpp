#include <bits/stdc++.h>
using namespace std;
int a[500005];
int num[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int> v;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		v.empty();
		v.push_back(a[i]);
		for(int j=i+1;j<n;j++)
		{
			for(double k=0;k<v.size();k++)
			{
				if(v[k]==a[j])
				{
					for(double x=0;x<v.size()-k;x++)
					{
						v.pop_back();
					}
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(double j=0;j<v.size();j++)
		{
			num[v[j]]++;
		}
	}
	for(int k=1;k<=m;k++)
	{
		cout<<num[k]<<" ";
	}
	return 0;
}
