#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans[300005],flag[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j,k,z;
	cin>>n>>m;
	ans[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			k=j;
			ans[a[j]]++;
		    flag[a[j]]++;
		    if(flag[a[j]]>1) 
		    {
		    	while(a[k]==a[j])
		    	{
				    k--;
				    ans[a[k]]--;
		    		flag[a[k]]=0;
		    	}
		    }
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
