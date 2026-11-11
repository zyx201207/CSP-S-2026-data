#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll dist,cishu;//jvli
};
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    ll c,T;cin>>c>>T;
    while(T--)
    {
        ll ans=0;
        ll n,d;cin>>n>>d;
        vector<ll>a(n+1);
        for(ll i=1;i<=n;i++) cin>>a[i];
        queue<unordered_map<ll,node>> q;
        unordered_map<ll,node> temp;
        temp[1].cishu=1;
        temp[1].dist=1;
        q.push(temp);
        ll i=1;
        while(!q.empty())
        {

            temp=q.front();q.pop();
            queue<unordered_map<ll,node>> p;
            ll j=i+q.size()+1;
            while(!q.empty())
            {
                unordered_map<ll,node> x=q.front();
                q.pop();
                for(auto &t:temp)
                {
                    if(x.find(t.first)!=x.end())
                    {
                        if(t.second.dist+1<x[t.first].dist)
                        {
                            x[t.first]=t.second;
                            x[t.first].dist+=1;
                            x[t.first].cishu=1;
                        }
                        else if(t.second.dist+1==x[t.first].dist)
                        {
                            x[t.first].cishu+=1;
                            if(x[t.first].cishu>2)
                            {
                                ans--;
                                 x.erase(t.first);
                            }
                            else if(x[t.first].cishu==2) ans++;
                        }
                    }
                    else 
                    {
                        x[t.first].dist=t.second.dist+1;
                        x[t.first].cishu=1;
                    }
                }
                p.push(x);
            }
            for(j;j<=n;j++)
            {
                if(a[j]-a[i]<=d)
                {
                    unordered_map<ll,node> o;
                    o[i].dist=j-i+1;
                    o[i].cishu=1;
                    p.push(o);
                }else break;
            }
            q=p;
            i++;
        }
        cout<<ans<<"\n";
    }

}
/*
qv chu ding bu yuansu

*/
