#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,n,m,d,q,w[500005],k,a[5005][500005]={0},t[5005][500005]={0},x,y;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>k;
        for(long long j=1;i<=k;j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(long long i=1;i<=q;i++)
    {
        cin>>x>>y;
        long long sss=0;
        for(long long j=1;j<=n;j++)
        {
            if(t[j][x]!=0)
            {
                sss+=t[j][x];
                break;
            }
        }
        for(long long j=1;j<=n;j++)
        {
            if(t[j][y]!=0)
            {
                sss+=t[j][y];
                break;
            }
        }
        cout<<w[x]+sss+w[y]<<endl;
    }
    return 0;
}
