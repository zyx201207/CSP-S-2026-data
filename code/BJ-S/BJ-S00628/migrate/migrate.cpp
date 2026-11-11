#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,t,ans;
const int maxN=1e4+10;
int x[maxN];
int B[maxN][maxN];

void f(int n,int d,int step,int now,int lz)
{
    if(step==2)
    {
        B[lz][now]++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(x[i]-now<=d)
            return f(n,d,step+1,x[i],lz);
        else
            break;
    }
    return;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=n;i++)
            f(n,d,0,x[i],x[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(B[i][j]>=2)
                    ans++;
        cout<<ans/2<<endl;
    }
    return 0;
}
