#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inl __attribute((always_inline)) inline
/*#define gc() getchar()
inl char gc()
{
    static char buf[1 << 20], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) : EOF ? *p1++;
}
inl int read()
{
    int x = 0, f = 1;
    char c = gc();
    while(!isdigit(c))
    {
        if(c == '-') f = -1;
        c = gc();
    }
    while(isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = gc();
    }
    return x * f;
}*/
struct Node
{
    int car;
    char tp[3];
} tic[2];
bool ans[4];
signed main()
{
    // freopen("travel.in", "r", stdin);
    // freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> tic[0].car;
    for (int i = 0; i < 3; i++)
        cin >> tic[0].tp[i];
    cin >> tic[1].car;
    for (int i = 0; i < 3; i++)
        cin >> tic[1].tp[i];

    if (tic[0].car == tic[1].car)
        ans[0] = true;
    if(!ans[0])
    {
    	for(int i = 1; i <= 4; i ++) cout << 0 << ' ';
    	return 0;
	}
    if (tic[0].tp[0] == tic[1].tp[0] && tic[0].tp[1] == tic[1].tp[1])
    {
        ans[1] = true;
        if (tic[0].tp[2] >= 'A' && tic[0].tp[2] <= 'C' && tic[1].tp[2] >= 'A' && tic[1].tp[2] <= 'C')
        {
            ans[2] = true;
            if (abs(tic[0].tp[2] - tic[1].tp[2]) == 1)
                ans[3] = true;
        }
        if (tic[0].tp[2] >= 'D' && tic[0].tp[2] <= 'F' && tic[1].tp[2] >= 'D' && tic[1].tp[2] <= 'F')
        {
            ans[2] = true;
            if (abs(tic[0].tp[2] - tic[1].tp[2]) == 1)
                ans[3] = true;
        }
    }
    for (int i = 0; i < 4; i++)
        cout << ans[i] << ' ';
    return 0;
}
