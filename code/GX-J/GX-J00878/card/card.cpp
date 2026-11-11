#include <bits/stdc++.h>
using namespace std;
long long i,j,l,n,m,s[300005],a[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=n;i>0;i--)
    {
        for (j=1;j<=i;j++)
        {
            int t=1;
            for (l=1;l<=j;l++)
            {
                if (!t)
                {
                    a[l]=0;
                }
                if(a[j]==a[l])
                {
                    t=0;
                }
            }
        }
        for (j=1;j<=n;j++)
        {
            if (a[j]!=0)
            {
                s[a[j]]++;
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        if (a[j]!=0)
        {
            cout<<a[j]<<" ";
        }
    }
    return 0;
}
