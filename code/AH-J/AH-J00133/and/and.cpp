#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+5;

int n,m;
long long a[maxn];

bool flag_A = 1;

struct num
{
    int a,b_len;
    int b[35];
}nums[maxn];

int do_fact(int num_idx)
{
    int cnt = 0;
    while(nums[num_idx].a)
    {
        nums[num_idx].b[++cnt] = nums[num_idx].a % 2;
        if(nums[num_idx].a % 2 == 0)
            flag_A = 0;
        nums[num_idx].a /= 2;
    }
    return cnt;
}

int maxa_i = -1;

void init()
{
    // cout << (int)'1' << endl;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i].a;
        maxa_i = max(maxa_i,nums[i].a);
        a[i] = nums[i].a;
        nums[i].b_len = do_fact(i);
        nums[i].a = a[i];
        // cout << a[i] << " ";
        // cout << nums[i].a << " ";

    }
}

int b[maxn];
int vis[maxn];

long long maxans = -1;

void dfs(int dep)
{
    if(dep > m)
    {
        // for (int i = 1; i <= m; i++)
        // {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        // a[b[i]] is input value;

        long long ans = a[b[1]];
        for(int i = 1; i <= m; i++)
        {
            ans &= a[b[i]];
        }
        maxans = max(maxans,ans);

        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << "HERR" << endl;
        if(vis[i]) 
        {
            continue;
        }
        vis[i] = 1;
        b[dep] = i;
        dfs(dep + 1);
        vis[i] = 0;
    }
}


void work()
{
    if(m == 1)
    {
        sort(a + 1, a + 1 + n,greater<int>());
        cout << a[1] << endl;
        return;
    }
    if(m == n)
    {
        long long ans = a[1];
        for (int i = 1; i <= m; i++)
        {
            ans &= a[i];
        }
        cout << ans << endl;
        return;
    }
    if(flag_A)
    {
        sort(a + 1, a + 1 + n,greater<int>());
        long long ans = a[1];
        // printf("ans : %d\n",ans);
        for (int i = 1; i <= m; i++)
        {
            ans &= a[i];
            // printf("ans : %d\n",ans);
        }
        cout << ans << endl;
        return;
    }
    if(maxa_i < 4)
    {
        int zero = 0;
        int oneg = 0;
        int twog = 0;
        int three = 0;
        for (int i = 1; i <= n; i++)
        {
            if(a[i] == 0) zero++;
            if(a[i] == 1) oneg++;
            if(a[i] == 2) twog++;
            if(a[i] == 3) three++;
        }

        if(m <= three)
        {
            cout << 3 << endl;
            return;
        }
        if(m <= three + twog)
        {
            cout << 2 << endl;
            return;
        }
        if(m <= three + oneg)
        {
            cout << 1 << endl;
            return;
        }

        cout << 0 << endl;
        return;
    }
    if(m == 2)
    {
        long long max_ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                long long ans = (a[i] & a[j]);
                max_ans = max(ans,max_ans);
            }
        }
        cout << max_ans << endl;
        return;
    }
    
    dfs(1);
    cout << maxans << endl;
    return;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    init();
    work();
    return 0;
}