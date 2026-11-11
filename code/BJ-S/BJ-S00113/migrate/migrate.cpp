#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000005],k,m,c,t,gai=0,ans=0;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        k=abs(a[2]-a[1]);
        m=d/k;
        if(m==1 || m==0) cout<<0<<'\n';
        else cout<<max(gai,(n-2*m+1))<<'\n';
    }
    return 0;
}
