#include <bits/stdc++.h>
using namespace std;
int a1[200005],a2[200005];
char b1[200005],b2[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a1[i] >> b1[i];
        a2[n + 1 - i] = a1[i];
        b2[n + 1 - i] = b1[i];
    }
    int l = 1,r = 1;
    long long sum = 0;

    while(l <= n && r <= n)
    {
        if(b1[l] != b2[r])
        {
            sum += min(a1[l],a2[r]);
        }
        int o = min(a1[l],a2[r]);
        a1[l] -= o;
        a2[r] -= o;
        if(a1[l] == 0) l++;
        if(a2[r] == 0) r++;
    }
    sum /= 2;
    string s;
    while(sum > 0)
    {
        s += char(sum % 10 + 48);
        sum /= 10;
    }
    reverse(s.begin(),s.end());
    cout << s;
}
