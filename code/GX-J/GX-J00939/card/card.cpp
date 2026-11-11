#include<bits/stdc++.h>
using namespace std;
long long a[5000005],b[5000005],z[2000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,s=1,w=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i1=1;i1<=n;i1++)
    {
        for(int i=i1;i<=n;i++)
        {
            b[w]=a[i];
            w++;
            s++;
            for(int j=1;j<=s;j++)
            {
                if(b[w]==b[j])
                {
                    for(int k=j;k<=s;k++)
                    {
                        if(b[k]!=0)
                        {
                            s--;
                            w--;
                            b[k]=0;
                        }
                    }
                    b[w]=a[i];
                }
            }
        }
        for(int i=1;i<=s;i++)
        {
            z[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<z[i]<<" ";
    }
    return 0;
}
