#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],c[500001],n,m;
int main()
{
    card.in>>n>>m;
    while(m==a[0])
    {
        for(int i=0;i<n;i++)
        {
            card.in>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            b[i]=a[i];
            for(int j=0;j<i-1;j++)
            {
                if(b[i]==b[j])
                {
                    for(int k=j;k<i;k++)
                    {
                        b[k]=0;
                    }
                    c[i]=b[i]
                }
            }
        }
        for(inti=0;i<n;i++)
        {
            a[i]=c[i]
        }
    }
    return 0;
}
