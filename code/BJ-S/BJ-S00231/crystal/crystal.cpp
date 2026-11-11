#include<bits/stdc++.h>
using namespace std;
long long a[600000],b[600000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            if(b[j]<b[j+1])
            {
                int t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
            }
        }
    }
    int v=0;
    for(int i=1;i<n;i++)
    {
        int cnt=0;
        for(int j=i+1;j<=n;j++)
        {
            cnt+=b[i]-b[j];

        }
          if((m-cnt)>=0)
        {
            v=n-i+1;
            cout<<v;
            break;
        }
    }
    return 0;
}
