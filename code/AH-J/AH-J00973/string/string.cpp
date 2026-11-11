#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,ans=0;
char c;
deque<char> s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++)
    {
        cin>>a>>c;
        for (ll j=1;j<=a;j++)
            s.push_back(c);
    }
    while (!s.empty())
    {
        if (s.front()!=s.back())
            ans++;
        s.pop_front();
        if (!s.empty())
            s.pop_back();
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}