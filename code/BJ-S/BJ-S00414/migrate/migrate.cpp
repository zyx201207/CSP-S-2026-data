#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int f,f2;
        cin>>f;
        for(int i=1;i<n;i++)
        {
            cin>>f2;
        }
        int dif=(f2-f)/(n-1);
        d=d/dif;
        if(d==1)
        {
            cout<<0<<endl;
            continue;
        }
        n--;
        int cnt=0;
        //cout<<n<<" "<<d<<endl;
        for(int i=2;i<=n;i++)
        {
            int x=ceil(i*1.0/d);
            //cout<<"x:"<<x<<endl;
            if(d*x-i==d-1)
            {
                //cout<<i<<endl;
                cnt+=(n-i+1);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
