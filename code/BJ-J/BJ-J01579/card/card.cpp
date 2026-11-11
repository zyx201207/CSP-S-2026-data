#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, m, a[N], tot, ans[N]; bool f=1;
map<int, int> cnt;
bool vis[N];
int main()
{
    //freopen("card.in", "r", stdin);
    //freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(i != 1 && a[i] > a[i-1]) f=0;
        if(i != 1 && a[i] != a[i-1]) tot++;
        //mp[a[i]] = i; //last occur id (manage
        cnt[a[i]]++;
    }
    if(f || (n >= 5000 && tot < 5000))
    {
        for(int i=1; i<=m; i++) cout << cnt[a[i]] << '\n'; //A B
        return 0;
    }
    for(int i=1; i<=n; i++) //i-n
    {
        queue<int> q;
        for(int j=i; j<=n; j++)
        {
            if(vis[a[j]])
            {int pos=-1; queue<int> qq; qq = q;
                for(int k=j-1; k>=i; k--)
                {
                    int qk = qq.front();
                    if(qk == a[j])
                        {pos=k; break;} qq.pop();
                }
                if(pos != -1)
                    {for(int k=1; k<j-pos; k++)
                        q.pop();}
            }
            q.push(a[j]);
            vis[a[j]] = 1;
        }
        while(q.size())
        {
            int ai = q.front(); //cout << ai << ' ';
            q.pop();
            ans[ai]++;
        }
        //cout <<endl;
    }
    for(int i=1; i<=m; i++) cout << ans[i] << ' ';
    return 0;
}
