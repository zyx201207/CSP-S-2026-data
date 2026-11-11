#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50005];
int main()
{
    freopen("card.in","r",stdin);
    reopen("card.out","w",stdout);
    cin>>n>>m;
    long long sum=1;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1])
        {
            sum++;
        }
        else
        {
            cout<<sum<<" ";
            if(a[i+1]!=a[i])
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
