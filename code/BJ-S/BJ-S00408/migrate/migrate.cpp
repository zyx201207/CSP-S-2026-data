#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
ll a[maxn];
ll le[maxn],ri[maxn];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll C,T;
    cin>>C>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ll l=1,r=1,id=1;
        for(;id<=n;id++)
        {
            while(l<n&&a[id]-a[l]>m)l++;
            while(r<n&&a[r+1]-a[id]<=m)r++;
            le[id]=l;
            ri[id]=r;
        }
        ll ans=0;
        for(int i=2;i<n;i++)
        {
            l=i;
            r=i+1;
            vector<ll> v;
            while(l>1&&a[i+1]-a[l-1]<=m)
            {
                l--;
                if(ri[l]>=i+2)continue;
                v.push_back(l);
            }
            while(v.size()&&l>1&&l!=le[l]&&ri[le[l]]==l)
            {
                l=le[l];
                v.push_back(l);
            }
            if(v.size()==0)continue;
            ll id=0;
            bool flag=false;
            while(r<n&&a[r+1]-a[i]<=m)
            {
                r++;
                if(le[r]<=i-1)continue;
                while(id<v.size()&&a[r]-a[v[id]]<=m)id++;
                while(id>0&&a[r]-a[v[id-1]]>m)id--;
                ans+=v.size()-id;
                if(id!=v.size())flag=true;
            }
            while(flag&&r<n&&r!=ri[r]&&le[ri[r]]==r)
            {
                r=ri[r];
                ans+=v.size();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
