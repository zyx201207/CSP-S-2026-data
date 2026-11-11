#include<bits/stdc++.h>
using namespace std;
long long ans=0,x[2000005],reach[2000005],c,t,n,d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t>0)
    {
        ans=0;
        cin>>n>>d;
        for(int i=0; i<n; i++)
        {
            cin>>x[i];
        }
        if(c==11||c==12)
        {
            if(d<=x[1]-x[0])
            {
                cout<<0<<endl;
                t--;
                continue;
            }
            d=d/(x[1]-x[0]);
            if(n>2*d-1)cout<<n-2*d+1<<endl;
            else cout<<0<<endl;
            t--;
            continue;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(x[j]-x[i]<=d)reach[i]=j;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=reach[i]+1; j<n; j++)
            {
                int cnt=0;
                for(int k=i+1; k<=reach[i]; k++)
                {
                    if(j<=reach[k])cnt++;
                    if(cnt>2)break;
                }
                if(cnt==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}
