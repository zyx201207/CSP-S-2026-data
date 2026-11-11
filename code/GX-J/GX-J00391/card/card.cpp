#include <bits/stdc++.h>
using namespace std;
long long a[10000005],dyute[10003345];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i<= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            dyute[i]=a[i];
            if(a[i]==a[j])
            {
                dyute[i]=a[i+1];
                continue;
            }
        }
    }
    for(int i = 1;i  <=n;i++)
    {

        cout << dyute[i] << " ";
    }
    return 0;
}
