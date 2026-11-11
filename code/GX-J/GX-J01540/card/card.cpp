#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,p=1;
    cin>>n>>m;
    int a[500000],o[300000]={0},w[300000]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int q=0;q<m;q++)
    {
        for(int i=q+1;i<=n;i++)
        {
            o[a[i]]++;
            if(o[a[i]]>1)
            {
                o[300000]={0};
                o[a[i]]++;
                p=a[i];
            }
        }
        o[300000]={0};
        for(int i=p;i<=n;i++)
        {
            w[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<w[i]<<" ";
    }
}
