#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,a[500010],cnt[500010];
vector<int> l;
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
		cin>>a[i];
	}
    for(int i=1;i<=n;i++)
    {
		l.clear();
		for(int j=i;j<n;j++)
		{
			bool h=0;
			for(int k=0;k<int(l.size());k++)if(l[k]==a[j])h=1;
			if(h==1)
			{
				int k=l.size()-1;
				while(l[k]!=a[j])
				{
					l.pop_back();
				}
				l.pop_back();
			}
			l.push_back(a[j]);
		}
		for(int j=0;j<m;j++)
		{
			bool h=0;
			for(int k=0;k<int(l.size());k++)if(l[k]==j)h=1;
			if(h==1)
			{
				cnt[m]++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<cnt[i];
	}
    return 0;
}
