#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200010
int n,m;
ll a[N],ans;
vector<int> id;
bool cmp(int x,int y)
{
    return a[x]>a[y];
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    ans=(1ll<<32)-1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=30;i>=0;i--)
    {
        id.clear();
        for(int j=n;j>=1;j--)
            if((a[j]>>i)&1) id.push_back(j);
        if(id.size()<m) continue;
        sort(id.begin(),id.end(),cmp);
        for(int j=1;j<=m;j++) ans&=a[id[j-1]];
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}