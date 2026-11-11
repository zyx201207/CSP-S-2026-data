#include<bits/stdc++.h>
using namespace std;
long long a[10005],b[10005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int j=0;
    for(int i=1;i<=n;i++)
    {
        int w=0;
        for(j=1;j<=n;j++)
        {
            if(b[j]!=a[i])
            {
               w=0;
            }
            else
            {
                w=1;
                b[j]=0;
            }
            else
            {
                for(int k=2;k<=n;k++)
                {
                    b[k]=0;
                }
            }
        }
        if(w==0)b[j]=a[i];
    }
    return 0;
}
