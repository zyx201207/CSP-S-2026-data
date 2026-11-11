#include<bits/stdc++.h>
using namespace std;
int a[500005];
int f[300005];
int ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    bool ff=true;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	if(i!=0)
    		if(a[i-1]>a[i])
    			ff=false;
	}
	if(ff==true)
	{
		int anss=0;
		for(int i=0;i<n;i++)
		{
			ans[a[i]]=i+1;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		vector<int> b;
		for(int j=i;j<n;j++)
		{
			if(f[a[j]]==1)
			{
				while(b.back()!=a[j])
				{
					f[b.back()]=0;
					b.pop_back();
				}
			}
			else
			{
				b.push_back(a[j]);
				f[a[j]]=1;
			}
		}
		for(auto& e:b)
			ans[e]++;
		memset(f,0,sizeof f);
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
    return 0;
}
