#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5,M=35;
int n,m,w,ans;
int a[N];
vector <int> t,t0;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        w=max(w,a[i]);
        t.push_back(i);
    }
    w=log2(w);
    ans=(1<<(w+1))-1;
    while(t.size()>m)
    {
        t0.clear();
        for(auto i:t)
            if((a[i]>>w)&1)
                t0.push_back(i);
        if(t0.size()>=m)
        {
            t.clear();
            for(auto i:t0) t.push_back(i);
        }
        if(w==0) break;
        w--;
    }
    for(auto i:t) ans&=a[i];
    cout<<ans;
    return 0;
}
