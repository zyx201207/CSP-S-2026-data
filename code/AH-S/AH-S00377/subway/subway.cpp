#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cnt=0;
int wi[500005],k[500005],ans[30]={0};
long long a[505][500005],t[505][500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
        cin>>c;
        memset(t,0x7f,sizeof(t));
        cnt++;
        cin>>n>>m>>d>>q;
        for(int i=1;i<=m;i++) cin>>wi[i];
        for(int i=1;i<=n;i++)
        {
            cin>>k[i];
            for(int j=1;j<=k[i];j++)
            {
                int h,z;
                cin>>h;
                a[i][h]=1;
                cin>>t[i][h];
            }
            while(q--)
            {
                int l,r;
                cin>>l>>r;
                for(int i=l;i<r;i++)
                {
                    ans[cnt]+=(wi[i]+t[i][i+1]);
                }
                ans[cnt]+=wi[r];
            }
        }
        cout<<ans[cnt]<<endl;
    return 0;
}
