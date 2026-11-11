#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2000010];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t,n,d;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=0;i<n;++i)
        {
            cin>>x[i];
        }

        bool flag=0;
        for(int i=1;i<n-1;++i)
        {
            if(x[i+1]-x[i]!=x[i]-x[i-1])
            {
                flag=1;
                break;
            }
        }
        int sum=0,tt=0;
        if(!flag) cout<<n-(d+d-1)<<endl;
        else{
            for(int i=tt;i<n-1;++i)
            {
                if(x[i]-d<x[i+1])
                {
                    if(i-(d+d-1)>0) sum+=i-(d+d-1);
                    tt=i+1;
                }
            }
            cout<<sum<<endl;
        }
    }


    return 0;
}
