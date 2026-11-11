#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long a[500002]; 
    int n,i;
    long long m,ans=0,max=0,ned,use;//ned 需求量
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
         cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
	    for(int j=1;j<=n;j++)
	    {
		    if(a[i]>=a[j])
		    {
			    swap(a[i],a[j]);
			}	
		}	
	}
    for(i=1;i<=n;i++)
    {
        ans=1;
        use=m;
        for(int j=i;j<=n;j++)
        {
			if(j==n)
			{
				break;
			}
            ned=a[i]-a[j];
            if(ned<=use)
            {
                ans++;
                use=use-ned;
            }
            else
            {
			    break;	
			}
        }
        if(max<=ans)
        {
            max=ans;
        }
    }
    cout<<max;
    return 0;
}
