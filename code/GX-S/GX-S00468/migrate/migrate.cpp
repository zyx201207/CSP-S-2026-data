#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N=2e6+100;
int n,d,c,T;
ll a[N],k,ans=0;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];

        }
        k=d/(a[2]-a[1]);
        if(k==0||k==1)
        {
            cout<<"0"<<"\n";
            continue;
        }
        cout<<max(ll(0),n-k*2+1)<<"\n";
    }
    return 0;
}
