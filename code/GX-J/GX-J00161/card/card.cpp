#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n;
    cin>>n;
    long long a[10000000];
    for(int i=1;i<=n;i+=1)
        cin>>a[i];
    long long b[10000000][10000000];
    long long m;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            b[i][j]=a[i][j];
            for(int k=1;k<j;k++)
            {
                if(b[i][k]==b[i][j])
                {
                    for(int l=j;l<n;l++)
                        b[i][l]=b[i][l+1];
                }
            }
        }

    }

    return 0;
}
