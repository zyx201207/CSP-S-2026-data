#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],ans[2000005],s[2000005];
bool pd(long long x)
{
	for(int i=1;i<=n;i++)if(s[i]==x)return true;
	return false;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    long long k=n;
    for(int cc=1;cc<=n;cc++)
    {
		memset(s,-1,sizeof s);
    	for(int i=cc;i<=n;i++)
	    {
	    	if(pd(a[i]))
	    	{
	    		for(int i=1;i<=n;i++)
					if(s[i]==a[i])
					{
						for(int j=i;j<=n;j++)s[j]=-1;
					}
				s[i]=a[i];
			}
			else
				s[i]=a[i];
		}
		for(int i=1;i<=n;i++)if(s[i]!=-1)ans[s[i]]++;
	}
    
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
