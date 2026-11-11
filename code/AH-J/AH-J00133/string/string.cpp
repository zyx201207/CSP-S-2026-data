#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6+5;

struct c
{
    long long x;
    long long x_s; // x 剩余
    
    char c;

}a[maxn];

long long n,L;
long long ans= 0;

void init()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].c;
        a[i].x_s = a[i].x;
        L += a[i].x;
    }
}

void work()
{
    long long head = 1;
    long long tail = n;
    while(head < tail)
    {
        auto &head_x = a[head];
        auto &tail_x = a[tail];

        if(head_x.c == tail_x.c)
        {
            if(head_x.x_s > tail_x.x_s)
            {
                head_x.x_s -= tail_x.x_s;
                tail_x.x_s = 0;
                --tail;
            }
            else if(head_x.x_s < tail_x.x_s)
            {
                tail_x.x_s -= head_x.x_s;
                head_x.x_s = 0;
                ++head;
            }
            else if(head_x.x_s == tail_x.x_s)
            {
                ++head;
                --tail;
            }
        }
        else if(head_x.c != tail_x.c)
        {
            // c's different
            if(head_x.x_s > tail_x.x_s)
            {
                ans += tail_x.x_s;
                head_x.x_s -= tail_x.x_s;
                tail_x.x_s = 0;
                --tail;
            }
            else if(head_x.x_s < tail_x.x_s)
            {
                ans += head_x.x_s;
                tail_x.x_s -= head_x.x_s;
                head_x.x_s = 0;
                ++head;
            }
            else if(head_x.x_s == tail_x.x_s)
            {
                ans += head_x.x_s; // or tail_x.x_s;
                ++head;
                --tail;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    init();
    work();
    return 0;
}