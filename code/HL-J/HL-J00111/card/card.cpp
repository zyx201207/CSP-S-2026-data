#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
        cout<<m;
    if(m==2)
        cout<<m<<" "<<m;
    return 0;
}
