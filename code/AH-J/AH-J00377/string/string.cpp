#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char c[200010];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;
    int ans=0;
    while(l<=r)
    {
        int gs=a[l];
        int t=gs;
        int tr=r;
        while(t>a[tr])
        {
            t-=a[tr];
            tr--;
        }
        if(t==a[tr])
        {
            for(int i=tr;i<=r;i++)
            {
                if(c[i]!=c[l]) ans+=a[i];
            }
            r=tr-1;
        }
        else if(t<a[tr])
        {
            if(c[tr]!=c[l]) ans+=t;
            for(int i=tr+1;i<=r;i++)
            {
                if(c[i]!=c[l]) ans+=a[i];
            }
            r=tr;
            a[tr]-=t;
        }
        l++;
    }
    cout<<ans;
}
