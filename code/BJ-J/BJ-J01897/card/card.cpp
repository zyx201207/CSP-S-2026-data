#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[500005];
ll h[300005];
ll h2[300005];
deque<ll> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(q.size())q.pop_front();
        for(int j=1;j<=m;j++)h[j]=0;
        for(int j=i;j<=n;j++)
        {
            h[a[j]]++;
            if(h[a[j]]>1)
            {
                while(1)
                {
                    if(q.back()==a[j])
                    {
                        q.pop_back();
                        break;
                    }
                    ll cu=q.back();
                    h[cu]--;
                    q.pop_back();
                }
                q.push_back(a[j]);
                h[a[j]]=1;
            }else{
                q.push_back(a[j]);
            }
        }
        while(q.size())
        {
            ll cu=q.front();
            h2[cu]++;
            q.pop_front();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<h2[i]<<" ";
    }
    return 0;
}
