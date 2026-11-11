#include<bits/stdc++.h>

using namespace std;

#define MAXN 500010
#define MAXM 300010

int n,m,a[MAXN];
int ans[MAXM];
vector<int> v;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("card5.in","r",stdin);
//	freopen("card5.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		v.clear();
		for(int j=i;j<=n;j++)
		{
			for(int k=0;k<v.size();k++)
			{
				if(v[k]==a[j])
				{
					int tmp=k,siz=v.size();
					while(tmp<siz)
					{
						v.pop_back();
						tmp++;
					}
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<v.size();j++)
		{
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
