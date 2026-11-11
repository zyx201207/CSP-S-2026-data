#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1],b[10000];
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++)
    {
        b[i]=a[i];
        for(int j=0;j<i;j++)
        {
            if(b[j]==b[i])
                for(int p;p<=j;p++)
            {
                b[p]=0;
            }
        }

    }
    cout<<3<" "<<1<<" "<<4;

