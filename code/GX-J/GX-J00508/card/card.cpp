#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    long long a[1000000],b[100000],c[100000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            c[j-i]=a[j];
            for(int y=0;y<j;y++)
            {
                if(c[j-i]==c[y])
                {
                    while((y-j+i-1))
                    {
                        a[i]=

                    }
                    break;

                }
            }
        }
    }
    return 0;
}
