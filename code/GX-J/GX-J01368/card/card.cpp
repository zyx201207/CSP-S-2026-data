#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p[500005],x[300005];
bool f[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(p,0,sizeof(p));
        memset(f,0,sizeof(f));
        int l=i;
        for(int j=i;j<=n;j++)
        {
            p[j]=a[j];
        }
        for(int j=i;j<=n;j++)
        {
            if(!f[p[j]])
            {
                f[p[j]]=true;
            }
            else
            {
                for(int k=i;k<=n;k++)
                {
                    if(p[k]==p[j])
                    {
                        l=k;
                        break;
                    }
                }
                for(int k=l;k<=j;k++)file:///home/noilinux/card/card.cpp

                {
                    p[k]=0;
                    if(k!=j)f[k]=false;
                }
            }

        }
        for(int j=i;j<=m;j++)
        {
            cout<<p[j]<<' ';
            x[p[j]]++;
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        if(i!=m)cout<<x[i]<<' ';
        else cout<<x[i];
    }
    return 0;
}


