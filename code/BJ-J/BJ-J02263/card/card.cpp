#include<bits/stdc++.h>
using namespace std;
long long a[20000005],b[20000005],c[1000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int cnt=i-1,f=i;
        for(int j=i;j<=n;j++)
        {
            b[++cnt]=a[j];
            for(int k=f;k<cnt;k++)
            {
                if(b[j]==b[k])
                {
                    f=cnt;
                }
            }
        }
        if(f!=1)
        {
            //cout<<cnt<<endl;
            for(int j=f;j<=n;j++)
            {
                //cout<<a[j]<<" ";
                c[a[j]]++;
                //cout<<a[j]<<" "<<j<<" "<<i<<endl;
            }
        }
        else
        {
            //cout<<cnt<<endl;
            for(int j=i;j<=n;j++)
            {
                c[a[j]]++;
                //cout<<a[j]<<" "<<j<<" "<<i<<endl;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}

