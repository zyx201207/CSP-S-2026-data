#include <bits/stdc++.h>
#define int long long
using namespace std;

int w[100005];
string s[1000005];
bool f[100005];
int n,m;
/*
void sto2(int w,int o)
{
    string p = "";
    int ans = 1;
    while (w)
    {
        p[ans] = '0' + (w % 2);
        w /= 2;
        ans++;
    }
    for (int i = 1; i <= ans - 1; i++)
    {
        s[o][i] = p[ans - i];
    }
}

int tots(string o)
{
    int p = 1,ans = 0;
    for (int i = o.size() - 1; i >= 0; i--)
    {
        int y = o[i] - '0';
        ans = ans * 10 + y * p;
        p *= 2;
    }
    return ans;
}

string ands(string l,string r)
{
    string ans = "";
    for (int i = max(l.size(),r.size()) - 1; i >= 0; i--)
    {
        if (l[l.size() + max(l.size(),r.size()) - i] == r[r.size() + max(l.size(),r.size()) - i])
        {
            ans[i] = '1';
        }
        else
        {
            ans[i] = '0';
        }
    }
    return ans;
}

void dfs(int step,int ans,string e)
{
    if (step == m)
    {
        maxn = max(maxn,ans);
        return;
    }
    if (step == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            dfs(step + 1,tots(s[i]),s[i]);
            cout << s[i] << endl;
            f[i] = 0;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (f[i]) continue;
            f[i] = 1;
            string k = ands(s[i],e);
            dfs(step + 1,tots(k),k);
            cout << k << " ";
            f[i] = 0;
        }
    }
    cout << ans << " ";
}
*/
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
       // sto2(w[i],i);
        maxn = max(maxn,w[i]);
    }
   // dfs(0,0,"");
    cout << maxn;
    return 0;
}
