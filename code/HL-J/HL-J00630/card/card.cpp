#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500001],ans[500001],found;
bool finx=0;
vector<int>temp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(j==1)
			{
				temp.push_back(a[j]);
				continue;
			}
			for(int k=0;k<j;k++)
			{
				if(temp[k]==a[j])
				{
					for(int l=k+1;l<temp.size();l++)
					{
						temp.pop_back();
					}
					finx=1;
					break;
				}
			}
			if(!finx)
			{
				temp.push_back(a[j]);
			}
			finx=0;
		}
		for(int i=0;i<temp.size();i++)
		{
			ans[temp[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
