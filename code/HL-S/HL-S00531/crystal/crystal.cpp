#include<iostream>
using namespace std;
int n,m,a[1000],s[1000];
int main()
{
    freopen(crystal.in,"r",stdin);
    freopen(crystal.out,"w",stdout);
  int ans=1,xn=0;

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        s[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {
            if(s[j]>=a[j+1])
            {
                int t=s[j];
                s[j]=s[j+1];
                s[j]=t;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(xn+s[i]<m)
        {
            xn+=s[i];
            ans++;
        }
        else break;
    }

    cout<<ans;
    return 0;

}
