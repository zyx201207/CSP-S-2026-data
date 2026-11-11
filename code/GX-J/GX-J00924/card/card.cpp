#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        a[i-1]=-1;
        for(int j=n;j>=i;j--)
        {
            if(a[i]==a[j])
            {
                for(int k=j;k<=n;k++)
                    a[i]=-1;
            }
        }
    }
    return 0;
}

