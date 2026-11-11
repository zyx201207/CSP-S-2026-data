#include<bits/stdc++.h>
#include<vector>
//Íê²»»ávector 
using namespace std;
int n,m;
const int MAXN = 1e5+5;
int a[MAXN],ans[MAXN];
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
		vector<int>v;
		for(int j=i;j<=n;j++)
		{
			
			for(int q=1;q<=v.size();q++)
			{
				if(v[q]==j)
				{
					for(int s=v[q];s<=v.size();s++)
					{
						v[s] = 0;
					}
					v[q]=a[j];
					continue;
				}
				
			}
			v[j] = a[j];
		}
		for(int q=1;q<=m;q++)
		{
			if(v[q]==i)
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		
			cout<<ans[i];
	}
	return 0;
}
