#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000002;

ll D;
int c,T,n;
ll x[MAXN];
ll d[MAXN];
ll cnt[MAXN];
ll sumd[MAXN];
int leftp[MAXN];
int rightp[MAXN];
int rightpn[MAXN];
bool vis[MAXN];
int sumc[MAXN];
bool visb[MAXN];
int leftc[MAXN];
int rightc[MAXN];

ll Get(int l,int r)
{
    if(l >= r) return 0;
    return sumd[r - 1] - sumd[l - 1];
}

int ccc;
int minvv;
bool bb[MAXN];
void Dfs(int step,int l,int r)
{
    if(step == r)
    {
        int p = l;
        int cccnt = 0;
        for(int i = l + 1;i <= r - 1;i++)
        {
            if(!bb[i]) continue;
            cccnt++;
            if(Get(p,i) > D) return;
            p = i;
        }

        if(Get(p,r) > D) return;
        if(cccnt < minvv)
        {
            minvv = cccnt;
            ccc = 1;
        }
        else if(cccnt == minvv) ccc++;
        return;
    }

    bb[step] = true;
    Dfs(step + 1,l,r);
    bb[step] = false;
    Dfs(step + 1,l,r);
}

void Do()
{
    ll ans = 0;
    for(int l = 1;l <= n;l++)
    {
        for(int r = l + 3;r <= n;r++)
        {
            ccc = 0; minvv = 0x3f3f3f3f;
            for(int i = l;i <= r;i++) bb[i] = false;
            Dfs(l + 1,l,r);
            if(ccc == 2) ans++;
        }
    }
    
    cout << ans << '\n';
}

void Clear()
{
    for(int i = 0;i <= n;i++)
        x[i] = d[i] = cnt[i] = sumd[i] = leftp[i] = rightp[i] = rightpn[i] = vis[i] = sumc[i] = visb[i] = leftc[i] = rightc[i] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> T;
    while(T--)
    {
        Clear();
        cin >> n >> D;
        for(int i = 1;i <= n;i++)
            cin >> x[i];
        for(int i = 1;i < n;i++)
            d[i] = x[i + 1] - x[i];
        for(int i = 1;i < n;i++)
            sumd[i] = sumd[i - 1] + d[i];
        
        if(n <= 9)
        {
            Do();
            continue;
        }

        leftp[1] = leftp[2] = -1;
        for(int i = 3;i <= n;i++)
        {
            if(Get(i - 1,i) > D || Get(1,i) <= D)
            {
                leftp[i] = -1;
                continue;
            }

            int p = i;
            for(int k = 21;k >= 0;k--)
                if(p - (1 << k) >= 1 && Get(p - (1 << k),i) <= D)
                    p -= (1 << k);
            if(p == 1) leftp[i] = -1;
            else
            {
                leftp[i] = p;
                cnt[p]++;
            }
        }

        rightp[n] = rightp[n - 1] = -1;
        for(int i = 1;i <= n - 2;i++)
        {
            if(Get(i,i + 1) > D || Get(i,n) <= D)
            {
                rightp[i] = -1;
                continue;
            }

            int p = i;
            for(int k = 21;k >= 0;k--)
                if(p + (1 << k) <= n && Get(i,p + (1 << k)) <= D)
                    p += (1 << k);
            if(p == n) rightp[i] = -1;
            else rightp[i] = p;
        }

        // cout << "leftp: "; for(int i = 1;i <= n;i++) cout << leftp[i] << " "; cout << '\n';
        // cout << "rightp: "; for(int i = 1;i <= n;i++) cout << rightp[i] << " "; cout << '\n';

        for(int i = 1;i <= n;i++)
            if(rightp[i] != -1)
                rightpn[rightp[i]] = i;
        for(int i = 1;i < n;i++)
            if(rightpn[i] != -1 && rightpn[i] + 1 == rightpn[i + 1])
                vis[rightpn[i]] = true;
        for(int i = 1;i <= n;i++)
            sumc[i] = sumc[i - 1] + (int)vis[i];
        
        leftc[1] = -1;
        for(int i = 2;i <= n;i++)
        {
            if(!vis[i - 1])
            {
                leftc[i] = -1;
                continue;
            }

            if(sumc[i - 1] == i - 1)
            {
                leftc[i] = 1;
                continue;
            }

            int p = i - 1;
            for(int k = 21;k >= 0;k--)
                if(p - (1 << k) >= 1 && sumc[i - 1] - sumc[(p - (1 << k)) - 1] == i - (p - (1 << k)))
                    p -= (1 << k);
            leftc[i] = p;
        }

        rightc[n] = -1;
        for(int i = 1;i < n;i++)
        {
            if(!vis[i + 1])
            {
                rightc[i] = -1;
                continue;
            }

            if(sumc[n] - sumc[i] == n - i)
            {
                rightc[i] = n;
                continue;
            }

            int p = i + 1;
            for(int k = 21;k >= 0;k--)
                if(p + (1 << k) <= n && sumc[p + (1 << k)] - sumc[i] == (p + (1 << k)) - i)
                    p += (1 << k);
            rightc[i] = p;
        }

        ll ans = 0;
        for(int s = 1;s <= n - 3;s++)
        {
            int y = rightp[s];
            int x = y - 1;
            ans += max(0ll,cnt[x] - 1);
            ll L = ((leftc[s] == -1) ? 1 : 1 + (s - 1 - leftc[s] + 1));
            ll R = ((rightc[s] == -1) ? 1 : 1 + (rightc[s] - (s + 1) + 1));
            ans += L * R;
        }

        cout << ans << '\n';
    }

    return 0;
}