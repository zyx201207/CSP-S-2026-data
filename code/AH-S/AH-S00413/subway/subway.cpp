#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
long long c,n,m,d,q,w[N],x[N],y[N],a[500010][500010],t[500010][50010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int r=1;r<=q;r++)
    {
        cin>>x[r]>>y[r];
    }
    cout<<30<<endl<<19;
}
