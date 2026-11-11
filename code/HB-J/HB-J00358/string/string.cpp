#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long number;
    char c;
};
bool check(vector<node> v)
{
    for(long long i = 1;i < v.size();i++)
        if(v[i].number != v[i - 1].number) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    vector<node> v(n);
    string s1 = "",s2 = "";
    for(long long i = 0;i < n;i++) cin>>v[i].number>>v[i].c;
    if(check(v) == true)
    {
        for(long long i = 0;i < n;i++) s1 += v[i].c;
        for(long long i = n - 1;i >= 0;i--) s2 += v[i].c;
        long long mid = n / 2;
        long long ans = 0;
        for(long long i = mid;i < n;i++)
            if(s1[i] != s2[i]) ans++;
        long long k = ans * v[0].number;
        cout<<k;
        return 0;
    }
    for(long long i = 0;i < n;i++)
        for(long long j = 0;j < v[i].number;j++)
            s1 += v[i].c;
    for(long long i = s1.size() - 1;i >= 0;i--) s2 += s1[i];
    long long mid = s1.size() / 2 + 1;
    long long ans = 0;
    for(long long i = mid;i < s1.size();i++)
        if(s1[i] != s2[i]) ans++;
    cout<<ans;
    return 0;
}
