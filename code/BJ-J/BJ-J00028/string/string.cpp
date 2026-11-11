#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2 * 1e5 + 1;

struct Node
{
    char c;
    ll a;

};

Node s[MAXN];
ll n, ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n;i ++) cin>>s[i].a>>s[i].c;

    ll r = 1, l = n;
    while(true)
    {
        ll sum = 0;
        while(sum <= s[r].a)
        {
            if(sum + s[l].a > s[r].a)
            {
                s[l].a -= (s[r].a - sum);
                if(s[l].c != s[r].c) ans += (s[r].a - sum);

                break;
            }else{
                sum += s[l].a;
                if(s[l].c != s[r].c) ans += s[l].a;
                if(l - 1 == r) break;
                else l--;
            }


        }

        if(r + 1 == l) break;
        else r++;


    }

    cout<<ans;

    return 0;
}
