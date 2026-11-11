#include<bits/stdc++.h>
using namespace std;
int n,m,card=1;
int ant[505],a[505],b[205],c[205];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ant[i];
        a[i]=ant[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=card;j<=n;j++)
        {
            if(b[a[j]]==0)
            {
                b[a[j]]=j;
            }
            else
            {
                for(int k=1;k<=b[a[j]];k++)
                {
                    a[k]=-1;
                }
            }
        }
        for(int l=1;l<=m;l++)
        {
            if(a[l]!=-1)
            {
                c[a[l]]++;
            }
        }
        card++;
        for(int y=1;y<=m;i++)
        {
            b[i]=0;
        }
        for(int r=1;i<=n;r++)
        {
            a[i]=ant[i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}

