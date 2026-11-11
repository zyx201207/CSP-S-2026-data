//GZ-J00295，卿可玥，贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    if(n==1)
    {
    	cout<<0;
    	return 0;
	}
    long long a[n];
    char b[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i]>>b[i];
	}
	int st=0,en=n-1;
	while(st<en)
	{
		if(a[st]>a[en])
		{
		    int p=en;
			a[st]-=a[en];
			if(b[st]!=b[en])
			{
				ans+=a[en];
			}
			en--;
		}
		else if(a[st]<a[en])
		{
			a[en]-=a[st];
			if(b[st]!=b[en])
			{
				ans+=a[st];
			}
			st++;
		}
		else
        {
            if(b[st]!=b[en])
            {
                ans+=a[st];
            }
            st++;
            en--;
        }
	}
	cout<<ans;
    return 0;
}
