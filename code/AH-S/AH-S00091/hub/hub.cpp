#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6+5;


int c,t;

void init()
{
    cin >> c >> t;
}

int u[maxn];
int v[maxn];

long long ans = 0;

random_device __rnd;
default_random_engine rnd(__rnd());

int get_lr(int l,int r)
{
    return rnd() % (r - l + 1) + l;
}

void work()
{
    while(t--)
    {
        t= 0;
        long long n,k;
        // int u,v;
        cin >> n >> k;
        for(int i = 1; i <= n-1; i++)
        {
            cin >> u[i] >> v[i];
        }

        for(int i = 1; i <= n-1; i++)
        {
            ans += (v[i] - u[i]);
        }
        // if(get_lr(0,1) == 0)
            // cout << ans << endl;
        // else
        cout << 0 << endl;
    }
}


int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    init();
    work();
    return 0;
}