#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    vector<int> s,t;
    s.reserve(n),t.reserve(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.push_back(a[i]);
    }
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        t.clear();
        int w=(1<<i);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]&w)
            {
                t.push_back(s[i]);
            }
        }
        if(t.size()>=m)
        {
            ans+=w;
            s=t;
        }
    }
    cout<<ans;
    return 0;
}