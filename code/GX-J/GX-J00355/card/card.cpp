#include<bits/stdc++.h>
using namespace std;
int n[1010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a,ans = 0;
    cin >> n >> m;

    for(int i = 1;i <= n;i++)
    {
        cin >> n[a];
        ans += n[a];
        if(n[a] != i)
        {
            ans += i;
        }
        else
        {
            ans -= n[a];
            ans += i;
        }
    }
     cout << ans;
    return 0;
}
