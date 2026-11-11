#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[10009],b[109][109],c[109][109],beg[1009],end[1009];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_std(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int f;
    for(int i=1;i<=n;i++){
        cin>>f;
        for(int j=1;j<=f;j++)
        {
            cin>>b[j][i]>>c[j][i];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>beg[i]>>end[i]
    }
    for(int i=1;i<=q;i++)
    {
        cout<<rand(1,10000);
    }
    return 0;
}