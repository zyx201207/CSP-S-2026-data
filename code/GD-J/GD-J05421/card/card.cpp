#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool b[500005];
int tot[500005];
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
		vector<int> num;
		for(int j=i;j<=n;j++)
		{
			int x;
			if(b[j]==0||num.empty())
			{
				num.push_back(a[j]);
				b[j]=1;
			}
			else
			{
				for(int k=1;k<=num.size();k++)
				{
					if(num[k]==a[j])
					{
						x=k;
						break;
					}
				}
				for(int k=x;k<=num.size();k++)
				{
					num.pop_back();
					b[k]=0;
				}
				num.push_back(a[j]);
				b[j]=1;
			}
		}
		for(int j=1;j<=num.size();j++)
		{
			tot[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tot[i]<<" "; 
	}
	return 0;
}
