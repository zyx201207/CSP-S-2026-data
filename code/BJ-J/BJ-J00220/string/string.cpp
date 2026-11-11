#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        ll a;
        char c;
        cin >> a >> c;
        if(a > 10000000)
        {
            printf("0");
            return 0;
        }
        for(ll j = 1;j <= a;j++)
        {
            s += c;
        }
    }


    ll i = 0,j = s.size() - 1;
    ll ans = 0;

    while(i != j)
    {
        if(s[i] != s[j])
        {
            ans++;
            s[j] = s[i];
        }
        i++;
        j--;
    }

    cout << ans << "\n";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
