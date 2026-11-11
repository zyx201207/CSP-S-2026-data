#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,edsum=1;
int d[500005];
int j[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>d[i];
    }
    sort(d+1,d+1+a);
    for(int i=1;i<=a;i++)
    {
        if(i==1)
        {
            j[i]=0;
        }
        else
        {
            j[i]=j[i-1]+(d[i]-d[i-1])*(i-1);
        }
    }
    for(int i=1;i<=a;i++)
    {
        int l=1,r=i,m,sum=0;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(j[i]-j[m]-(m-1)*(d[i]-d[m])<=b)
            {
                sum=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        edsum=max(edsum,i-sum+1);
    }
    cout<<edsum;
    return 0;
}
