#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct s
{
    string s;
    int v;
}a[N];
ll n, m, b[N];
ll ans;
bool cmp(s A, s B)
{
    for(int i=0;i<=30;i++)
    {
        if(A.s[i]!=B.s[i]) return A.s[i]>B.s[i];
    }
    return A.s>B.s;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll res=(1ll<<31)-1;
    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        a[i].s.resize(31);
        a[i].v=v;
        int cnt=30;
        while(v)
        {
            a[i].s[cnt--]=v%2;
            v/=2;
        }
    }
    res=0;
    sort(a+1, a+1+n, cmp);
    for(int i=0;i<=30;i++)
    {
        int cnt=0;
        ans=(1ll<<31)-1;
        vector<int> aa;
        for(int j=1;j<=n;j++)
        {
            if(a[j].s[i]==1)
            {
                ans&=a[j].v;
                cnt++;
            }
            if(cnt==m)
            {
                res=max(res, ans);
            }
        }
    }
    cout<<res;
    return 0;
}
