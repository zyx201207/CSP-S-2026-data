#include<iostream>
#include<cstdio>
using namespace std;
long long c,d,m,n,k[500],q,w[500005],a[505][505],t[505][505],rx[100005],ry[100005],ans;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>rx[i]>>ry[i];
        ans+=w[rx[i]]+=w[ry[i]];
    }
    return 0;
    //我真不会了睡了兄弟
}
