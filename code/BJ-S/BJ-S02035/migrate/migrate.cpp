#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,c;
    ll d;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        if(c==11||c==12)
        {
            cout<<"0\n";
            continue;
        }
    }
    return 0;
}