#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
long long n,m,a[maxn],ansa,ansb;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        cout<<n;
    }
    if(m==2)
    {
        for(int i = 1;i<=n;i++)
        {
            if(a[i]==1) ansa++;
            if(a[i]==2) ansb++;
        }
        if(ansa%2==0) ansa++;
        if(ansb%2==0) ansb++;
        if(a[n]==1) cout <<n<<' '<<ansb;
        if(a[n]==2) cout <<ansa<<' '<<n;
    }
    return 0;
}

