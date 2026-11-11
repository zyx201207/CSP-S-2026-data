#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=2e6+5;
int n,d,c,t;
int a[N];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        LL res=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]-a[j]+1==2*d)
                {
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
