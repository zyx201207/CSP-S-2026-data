#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        long long ans=0;
        long long d;
        int n;
        vector<long long> v(5005);
        cin>>n>>d;
        int o=0;
        for(int i=1;i<=n;i++)
        {
            long long x;
            cin>>x;
            if(i==1){v[i]=x;o++;continue;}
            if(x-v[i-1]>d)continue;
            v[i]=x;
            o++;

        }
        n=o;
        for(int k=1;k<=n-3;k++)
        {
                int cnt=0;
                for(int j=1;j<=n-2;j++)
                {
                    if(-v[k]+v[k+j]<=d&&-v[k+j]+v[n]<=d)cnt++;
                    //cout<<k<<' '<<j+k<<' '<<n<<' '<<cnt<<endl;
                }
                if(cnt==2)ans++;


        }
        cout<<ans<<'\n';
    }
    return 0;
}
