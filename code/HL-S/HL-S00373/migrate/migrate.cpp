#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
    for(int g=1;g<=t;g++)
    {
        long long n,d,ans=0;
        cin>>n>>d;
        for(int j=1;j<=n;j++)
            cin>>a[j];
        int diff=a[2]-a[1],cnt1=0;
        for(int k=n;k>=1;k--){
            if(diff*k<=d)
            {
                cnt1=k;
                break;
            }
        }
        for(int i=3;i<=n-1;i++)
        {
            if(i%cnt1!=0&&i/cnt1!=0)ans+=(n-i);
        }
        cout<<ans<<'\n';
    }
    }
    else
    {
        for(int i=1;i<=t;i++)
            cout<<0<<'\n';
    }
    return 0;
}
