#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
stack<ll> t;
multiset<ll> s;
ll a[N],vis[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(s.find(a[j])==s.end())
            {
                t.push(a[j]);
                s.insert(a[j]);
            }
            else
            {
                while(s.find(a[j])!=s.end())
                {
                    s.erase(s.find(t.top()));
                    t.pop();
                }
                t.push(a[j]);
                s.insert(a[j]);
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(s.find(i)!=s.end())
            {
                vis[i]++;
            }
        }
        while(!t.empty())
        {
            t.pop();
        }
        s.clear();
    }
    for(int i=1;i<=m;i++) cout<<vis[i]<<" ";
    cout<<endl;
    return 0;
}
