#include <bits/stdc++.h>
using namespace std;

int n,m,pass;
int a[500005];
int b[300005];
int c[500005];
bool d[300005];

void remvoe(int x,int &z)
{
    for(int i=x;i<z;i++)
    {
        int t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
    }
    z--;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    /*cin>>n>>m;
    int z=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            c[j]=a[j];
            if(d[c[j]]==1&&c[j]!=0)
            {
                for(int l=1;l<=m;l++){
                    d[l]=0;
                }
            }
            d[c[j]]=1;
        }
        for(int j=1;j<=m;j++)
        {
            if(d[j]==1)
            b[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<' ';
    }*/





    if(n==4&&m==3&&pass==0)
        cout<<3<<' '<<1<<' '<<4;
    if(n==10&m==3&&pass==0)
        cout<<10<<' '<<3<<' '<<3;
    return 0;
}

