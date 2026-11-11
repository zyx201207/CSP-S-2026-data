#include <iostream>
using namespace std;
int a[500005],d[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,c=0,ans=0;
    cin>>n>>m;
    if(n<=5000)
    {
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            d[i]=d[i-1]+a[i];
            int sum=0,mx=-1e9;
            for(int j=i; j>=1; j--)
            {
                mx=max(mx,a[j]);
                if(a[j]>a[i])
                {
                    ans=max(ans,i-j);
                    break;
                }
                if(mx*(i-j+1)-d[i]+d[j-1]>m)
                {
                    ans=max(ans,i-j);
                }
            }
        }
        cout<<ans;
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            d[i]=d[i-1]+a[i];
            //cout<<a[i]*(i-c-1)+d[c]-d[i-1]<<" "<<c<<endl;
            while(a[i]*(i-c-1)+d[c]-d[i-1]>m)
            {
                c++;
            }
            ans=max(ans,i-c);
            //cout<<i-c<<endl;
        }
        cout<<ans;
    }



    return 0;
}
