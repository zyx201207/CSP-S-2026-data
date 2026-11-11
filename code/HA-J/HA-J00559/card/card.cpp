#include<bits/stdc++.h>
using namespace std;
int a[500005];
int num[300005];
int ans[300005];
bool f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	num[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
    	num[a[i-1]]--;
    	for(int j=i;j<=n;j++)
    	{
    		if(num[a[i]]!=1)
    		{
    			if(f[a[i]]==0)
				{
					ans[a[i]]++;
					f[a[i]]=1;
				}
    			break;
    		}
    		else 
    		{
    			if(f[a[i]]==0)
				{
					ans[a[i]]++;
					f[a[i]]=1;
				}
    		}
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	num[a[i]]++;
    }
    ans[n]=n;
    for(int i=1;i<=m;i++)
    {
    	cout<<max(ans[i],num[i])<<' ';
    }
	return 0;
}

