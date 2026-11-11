#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    unsigned long long m,x;
    unsigned int i,n,ans=0,y;
    int j;
    bool f=1;
    cin>>n>>m;
    long long a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=i+1) f=0;
    }
    if(f)
    {
        i=sqrt(2*m);
        while(i*i+i<=2*m) i++;
        cout<<--i;
    }
    else
    {
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
            x=0,y=1;
            for(j=i;j>0;j--)
            {
                x+=a[i]-a[j];
                if(x<=m) y++;
                else
                {
                    ans=max(ans,y);
                    break;
                }
                if(j-1<0)
                {
                    ans=max(ans,y);
                    break;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
