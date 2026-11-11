#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010];
struct node
{
    int x;
    bool flag;
}y[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>y[i].x;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<n<<' ';
    }
    return 0;
}
