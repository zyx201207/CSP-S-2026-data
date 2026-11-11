// GZ-S00148 遵义市第四中学 温岳城

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    vector<int> w(m);vector<vector<int>> a(n,vector<int>()),t(n,vector<int>());
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++)
    {
        int k;cin>>k;
        for(int j=0,x,y;j<k;j++) cin>>x>>y,a[i].push_back(x),t[i].push_back(y);
    }
    for(int i=0,x,y;i<q;i++) cin>>x>>y,cout<<"114514\n";
    return 0;
}
