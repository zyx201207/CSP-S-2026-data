#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int maxx=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            maxx=max(maxx,a[i]&a[j]);
        }
    }
    cout<<maxx;

    return 0;
}
