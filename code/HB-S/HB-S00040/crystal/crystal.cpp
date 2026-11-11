#include<bits/stdc++.h>
using namespace std;
const int M=5e5+2,Q=1e8;
int n,m,a[M],d[M],maxi=1,sum=0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);
    if(m>Q)
    {
        if((a[2]-a[1])==1)
        {
            int x=m/2+1;
            while((x+x*x)/2!=m)
            {
                if((x+x*x)/2<m)
                    x=x+(x/2+1);
                else
                    x=x-(x/2+1);
            }
            cout<<x+1;
        }
        else
        {
            int y=a[2]-a[1];
            int x=m/2+1;
            while((y+m)*m/2!=m)
            {
                if((y+m)*m/2<m)
                    x=x+(x/2+1);
                else
                    x=x-(x/2+1);
            }
            cout<<x+1;
        }

    }
    for(int i=1;i<n;i++)
        d[i]=a[i+1]-a[i];
    int l=1,r=1;
    while(r<=n&&l<=r)
    {
        sum=0;
        for(int i=l;i<=r;i++)
            sum+=a[r]-a[i];
        if(sum>m)
            l++;
        else
        {
            maxi=max(maxi,(r-l+1));
            r++;
        }

    }
    cout<<maxi;
    return 0;
}
