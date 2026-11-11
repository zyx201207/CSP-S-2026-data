#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=2e6+5;
ll c,t,x[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        bool flag=1;
        ll last=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            if(i==1)
            {
                continue;
            }
            else if(i==2)
            {
                last=x[i]-x[i-1];
            }
            else{
                if(x[i]-x[i-1]!=last)
                {
                    flag=0;
                }
            }
        }
        if(flag==1)
        {
            if(d<last)
            {
                cout<<0<<'\n';
            }
            else
            {
                int c=last*(n-1)/d;
                cout<<c<<'\n';
            }
        }
        else{

            cout<<n-d<<'\n';
        }
    }
    return 0;
}
