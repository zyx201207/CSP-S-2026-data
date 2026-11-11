#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005,mod=998244353;
ll n,c,T,k,f[N];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1,x,y;i<n;i++)
        {
            cin>>x>>y;
        }
        if(n==k)cout<<"0\n";
        else cout<<"1\n";
    }
    return 0;
}
//
