#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int c,t;
const int N=2e6+10;
int a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        bool A=1;
        int cc;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i==2)
            {
                cc=a[i]-a[i-1];
            }
            if(i!=1)
            {
                if(cc!=a[i]-a[i-1])A=0;
            }
        }
        if(c==11||c==12||A==1)
        {
            int cha=abs(a[1]-a[2]);
            //cout<<cha<<" "<<d<<" "<<d-cha<<endl;
            if(cha>=d)cout<<0<<endl;
            else if(d-cha<cha)cout<<0<<endl;
            else
            {
                d=d/cha;
                d=d*2-1;
                //cout<<d<<endl;
                if(d>n)cout<<0<<endl;
                else cout<<n-d<<endl;
            }
            continue;
        }
        if(abs(a[1]-a[n])<=d)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int cnt=0;
                for(int k=i+1;k<j;k++)
                {
                    if(abs(a[j]-a[i])>d&&abs(a[k]-a[i])<=d&&abs(a[j]-a[k])<=d)
                    {
                        cnt++;
                        //cout<<i<<" "<<j<<" "<<k<<endl;
                    }
                }
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
