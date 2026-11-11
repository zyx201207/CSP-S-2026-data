#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],aa[500005];
long long b[500005],mb[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i <= n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i <= n;i++)
    {
        for(int j=1;j <= n;j++)
        {
            aa[j]=a[j];
        }
        for(int j=i;j <= n;j++)
        {
            if(b[aa[j]] == 1)
            {
                int ii=j-1,aaa=aa[j];
                aa[j]=0;
                b[aa[j]]=1;
                while(1)
                {
                    if(aa[ii] == aaa)
                    {
                        break;
                    }
                    b[aa[ii]]=0;
                    aa[ii]=0;
                    ii--;
                }
            }
            else
            {
                b[aa[j]]++;
            }
        }
        for(int j=i;j <= n;j++)
        {
            if(aa[j] > 0)
            {
                mb[aa[j]]++;
            }
        }
        for(int j=0;j <= m;j++)
        {
            b[j]=0;
        }
    }
    for(int i=1;i <= m;i++)
    {
        cout<<mb[i]<<" ";
    }
    return 0;
}
