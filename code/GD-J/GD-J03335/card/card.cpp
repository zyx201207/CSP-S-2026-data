#include <bits/stdc++.h>
using namespace std;

long long n,m,idx=1;
long long a[500005];
long long res[500005]={0};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int turn=1;turn<=n;turn++)
	{
		long long desktop[500005];
		long long pos[500005]={0};
		idx=1;
		for(int i=turn;i<=n;i++)
		{
			if(pos[a[i]]!=0)
			{
				for(int del=pos[a[i]]+1;del<idx;del++)
				{
					pos[desktop[del]]=0;
					desktop[del]=0;
				}
				idx=pos[a[i]]+1;
			}
			else
			{
				desktop[idx]=a[i];
				pos[a[i]]=idx;
				idx++;
			}
		}
		for(int r=1;r<idx;r++)
		{
			res[desktop[r]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<res[i]<<" ";
	}

	return 0;
}
