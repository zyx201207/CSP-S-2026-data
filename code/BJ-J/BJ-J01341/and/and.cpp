#include<iostream>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,m;
ll a[N],out[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        out[i]=0;
    }
    ll ans=0;
    for(int k=29;k>=0;k--)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(out[i])continue;
            int x=((a[i]>>k)&1);
            if(x==1)
            {
                cnt+=1;
            }
        }
        if(cnt<m)continue;
        ans=(ans|(1<<k));
        for(int i=1;i<=n;i++)
        {
            if(out[i])continue;
            int x=((a[i]>>k)&1);
            if(x==0)
            {
                out[i]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}