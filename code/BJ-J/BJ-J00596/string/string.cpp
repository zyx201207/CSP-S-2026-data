#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using pi=pair<int,int>;
#define fi first
#define se second
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j,k;
    cin>>n;
    vector<pair<ll,char>>a(n+1);
    vl b(n+1,0);
    vl s(n+1,0);
    ll js=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].fi>>a[i].se;
        s[i]=s[i-1]+a[i].fi;
        js+=a[i].fi;
        b[i]=a[i].fi;
    }
    int r=n;
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        ll x=a[i].fi;
        for(j=r;j>i;j--)
        {
            if(x>=b[j])
            {
                x-=b[j];
                if(a[j].se!=a[i].se)
                {
                    ans+=b[j];
                    b[j]=0;
                }
                
            }
            else
            {
                if(a[j].se!=a[i].se)
                {
                    ans+=x;
                }
                b[j]-=x;
                break;
            }
        }
        if(j==i) break;
        r=j;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
3
2 a
2 b
1 c
*/