#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt=0;
vector<int> v;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    char c;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x>>c;
        for(int i=0;i<x;i++){
            v.push_back(c-'a');
            cnt++;
        }
    }
    int ans=0;
    for(int i=0;i<signed(ceil(cnt*1.0/2));i++)
    {
        if(v[i]!=v[cnt-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
