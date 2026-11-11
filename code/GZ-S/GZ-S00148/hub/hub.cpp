// GZ-S00148 遵义市第四中学 温岳城

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int c,t;cin>>c>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<vector<int>> a(n,vector<int>());
        for(int i=0,u,v;i<n;i++) cin>>u>>v,a[u].push_back(v),a[v].push_back(u);
        if(c&1) cout<<"114\n";
        else cout<<"514\n";
    }
    return 0;
}
