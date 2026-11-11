#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010

ll n,m,w[N];
ll l,now=0,ans=1;
queue<ll> q;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m; l=m;
    for(ll i=1;i<=n;i++) cin>>w[i];

    sort(w+1,w+n+1);

    now=w[1];
    q.push(w[1]);
    for(int i=2;i<=n;i++)
    {
        while(!q.empty()&&(l<((w[i]-now)*(ll)q.size())))
        {
            ll t=q.front(); q.pop();
            l=l+(now-t);
        }
        if(l>=((w[i]-now)*(ll)q.size()))
        {
            l=l-(w[i]-now)*(ll)q.size();
            now=w[i];
            q.push(w[i]);
        }
        ans=max(ans,(ll)q.size());
    }
    cout<<ans<< "\n";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
