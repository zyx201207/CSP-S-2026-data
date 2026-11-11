#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2E5 + 10;
int n;
ll a[N];
char c[N];
string s;
ll maxa;

void solve1()
{
    for(int i = 1; i <= n; i++)
    {
        char k = c[i];
        for(int j = 1; j <= a[i]; j++)
            s += k;
    }
    int len = s.size();
    s = " " + s;
    ll ans = 0;
    for(int i = 1; i <= len / 2; i++)
    {
        if(s[i] != s[len - i + 1]) ans++;
    }
    cout<<ans;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        maxa = max(maxa, a[i]);
        cin>>c[i];
    }
    if((n <= 2000 && maxa <= 50) || (n <= 200000 && maxa <= 50))
    {
        solve1();
    }
	return 0;
}
