#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll cnt,num,px,xx;
priority_queue<ll> q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        ll x;
        scanf("%lld",&x);
        q.push(-x);
    }
    while(!q.empty())
    {
        xx=-q.top();
        px=-q.top();
        while(!q.empty())
        {
            ll x=-q.top();
            if(x==px)
            {
                num++;
                //px=x;
                q.pop();
            }
            else
            {
                xx=x;
                break;
            }
        }
        //cout<<px<<" "<<xx<<" "<<cnt+(xx-px)*num<<"\n";
        if(cnt+(xx-px)*num<=m)cnt+=(xx-px)*num;
        else break;
    }
    cout<<num;
    return 0;
}
