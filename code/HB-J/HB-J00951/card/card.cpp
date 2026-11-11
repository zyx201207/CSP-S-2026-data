#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long  n,m;
    cin>>n>>m;
    long long a[n+5],b[n+5],c[m+5]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=1;l<=n;l++)
    {
        b[n+5]={0};
        int s=0;
        for(int i=l;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[j]==a[i])
                {
                    int t=s;
                    for(int k=j;k<=t;k++)
                    {
                        s--;
                        b[k]=0;
                    }
                    break;
                }
            }
            s+=1;
            b[s]=a[i];

        }
        for(int j=1;j<=s;j++)
        {
            c[b[j]]+=1;
        }
    }

    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }


    return 0;
}

