#include<bits/stdc++.h>
using namespace std;

int main()
{

    long long n,m,sum=0;
     a[500005];
    for(int i;i<=n;i++)
    {

        cin>>a[i]>>" ";
    }
    sort(0,n,a);
    if(n%2==0)
    {
        for(int j;j<=n-1;j++)
        {
            if(a[j]=a[j+1])
            {
                sum+=1;
            }
        }
        if(sum=n-1&&sum<=m)
        {
            cout<<n;
        }
        else if(sum=n-1&&sum>m)
	    {
            cout<<m;
        }
        else
	    {
            cout<<n/2+sum;
	    }
    }
    else
    {
     	for(int j;j<=n-1;j++)
	    {
            if(a[j]=a[j+1])
            {
             	sum+=1;
            }
	    }
        if(sum=n-1&&sum<=m)
	    {
            cout<<n;
        }
        else if(sum=n-1&&sum>m)
	    {
            cout<<m;
	    }
	    else
	    {
            cout<<n/2+1+sum;
	    }
    }
}

