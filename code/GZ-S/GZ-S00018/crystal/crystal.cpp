//GZ-S00018 µËÔÆÐù
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	long long ans=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	long long e=m;
    	long long sum=0;
    	for(int j=1;j<=n;j++)
    	{
    		b[j]=a[j];
		}
    	for(int j=1;j<i;j++)
    	{		
    	    while(b[j]<b[i]&&e)
    	    {
    		    b[j]++;
    		    e--;
		    }
		    if(e==0)break;
		}
		for(int j=1;j<n;j++)
	    {
		    if(b[j]==b[j+1])
		    {
			    sum++;
		    }
	    }
	    ans=max(ans,sum);
	}
	cout << ans+1;
	return 0;
}
