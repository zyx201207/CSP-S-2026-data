#include<bits/stdc++.h>
using namespace std;
long long a[200010],maxn=0,b[200010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    for(int i=1;i<=n;i++)
    {
    	q.push(a[i]);
    	for(int j=i;j>=1;j--)
    	{
    		if(a[i]==a[j])
    		{
    			for(int k=i;k<=j;k++)
    			{
    			    q.pop();	
				}
			}
		}
		for(int j=q.front();j<=q.back();j++)
		{	
		    b[j]++;	  
		}
    }
	for(int i=1;i<=m;i++)
	{
		if(i==m)
		{
			cout<<n;
			break;
		}
		cout<<b[i]<<" ";
	}
    return 0;
}