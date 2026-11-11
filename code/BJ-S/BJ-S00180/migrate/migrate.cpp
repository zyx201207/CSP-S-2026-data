#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t,n,d;
ll a[2000010];
bool fl=1;
ll dd=0;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
   // cout<<c<<"^" <<t<<'\n';
    while(t--)
    {
        fl=1;
        //memset(a,0,sizeof(a));
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
     //   cout<<"CCC" <<t<<' '<<n<<' '<<d<<'\n';
        ll ddd=a[2]-a[1];
  //      cout<<"W" <<ddd<<'\n';
        for(ll i=3;i<=n;i++)
        {
            ll dddd=a[i]-a[i-1];
            if(dddd!=ddd)
            {
                fl=0;
    //            cout<<"&" <<i<<'\n';
                break;
            }
        }
        if(fl)
        {
    //        cout<<"*" <<t<<'\n';
            ddd=abs(ddd);
            ll w=d/ddd;
   //         cout<<"Q"<<d<<' '<<ddd<<' ' <<w<<'\n';
            if(w==0)
            {
 //               cout<<0<<'\n';
                continue;
            }

  //          cout<<"P"<<n<<' '<<n-(2*w)+1<<' ' <<(w-1)<<'\n';
            cout<<(n-(2*w)+1)*(w-1)<<'\n';

        }
        else
        {
            cout<<0<<'\n';
        }
    }
    return 0;
}
