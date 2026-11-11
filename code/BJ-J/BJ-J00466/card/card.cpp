#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
string s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        s = {};
        for(int j = i;j <= n;j++)
        {
            if(s.find(a[j] + 48) != string::npos)
            {
                s = s.substr(0,s.find(a[j] + 48));
            }
            s += (a[j] + 48);
        }
        for(int j = 1;j <= m;j++)
        {
            if(s.find(j + 48) != string::npos)
            {
                ans[j]++;
            }
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}