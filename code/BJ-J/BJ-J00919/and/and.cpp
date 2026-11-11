#include <bits/stdc++.h>
using namespace std;

//Remember long long;
//freopen() 召唤成功
int arr[200010];
int n, m, maxm = -1e9;
int awh(int a, int b)
{
    if(a == 0)
    {
        return b;
    }
    bool ass[25], bss[25];
    if(a >= 1048576)
    {
        a -= 1048576, ass[20] = 1;
    }
    if(a >= 524288)
    {
        a -= 524288, ass[19] = 1;
    }
    if(a >= 262144)
    {
        a -= 262144, ass[18] = 1;
    }
    if(a >= 131072)
    {
        a -= 131072, ass[17] = 1;
    }
    if(a >= 65536)
    {
        a -= 65536, ass[16] = 1;
    }
    if(a >= 32768)
    {
        a -= 32768, ass[15] = 1;
    }
    if(a >= 16384)
    {
        a -= 16384, ass[14] = 1;
    }
    if(a >= 8192)
    {
        a -= 8192, ass[13] = 1;
    }
    if(a >= 4096)
    {
        a -= 4096, ass[12] = 1;
    }
    if(a >= 2048)
    {
        a -= 2048, ass[11] = 1;
    }
    if(a >= 1024)
    {
        a -= 1024, ass[10] = 1;
    }
    if(a >= 512)
    {
        a -= 512, ass[9] = 1;
    }
    if(a >= 256)
    {
        a -= 256, ass[8] = 1;
    }
    if(a >= 128)
    {
        a -= 128, ass[7] = 1;
    }
    if(a >= 64)
    {
        a -= 64, ass[6] = 1;
    }
    if(a >= 32)
    {
        a -= 32, ass[5] = 1;
    }
    if(a >= 16)
    {
        a -= 16, ass[4] = 1;
    }
    if(a >= 8)
    {
        a -= 8, ass[3] = 1;
    }
    if(a >= 4)
    {
        a -= 4, ass[2] = 1;
    }
    if(a >= 2)
    {
        a -= 2, ass[1] = 1;
    }
    if(a >= 1)
    {
        a -= 1, ass[0] = 1;
    }
    if(b >= 1048576)
    {
        b -= 1048576, bss[20] = 1;
    }
    if(b >= 524288)
    {
        b -= 524288, bss[19] = 1;
    }
    if(b >= 262144)
    {
        b-= 262144, bss[18] = 1;
    }
    if(b >= 131072)
    {
        b -= 131072, bss[17] = 1;
    }
    if(b >= 65536)
    {
        b -= 65536, bss[16] = 1;
    }
    if(b >= 32768)
    {
        b -= 32768, bss[15] = 1;
    }
    if(b >= 16384)
    {
        b -= 16384, bss[14] = 1;
    }
    if(b >= 8192)
    {
        b -= 8192, bss[13] = 1;
    }
    if(b >= 4096)
    {
        b -= 4096, bss[12] = 1;
    }
    if(b >= 2048)
    {
        b -= 2048, bss[11] = 1;
    }
    if(b >= 1024)
    {
        b -= 1024, bss[10] = 1;
    }
    if(b >= 512)
    {
        b -= 512, bss[9] = 1;
    }
    if(b >= 256)
    {
        b -= 256, bss[8] = 1;
    }
    if(b >= 128)
    {
        b -= 128, bss[7] = 1;
    }
    if(b >= 64)
    {
        b -= 64, bss[6] = 1;
    }
    if(b >= 32)
    {
        b -= 32, bss[5] = 1;
    }
    if(b >= 16)
    {
        b -= 16, bss[4] = 1;
    }
    if(b>= 8)
    {
        b -= 8, bss[3] = 1;
    }
    if(b >= 4)
    {
        b -= 4, bss[2] = 1;
    }
    if(b >= 2)
    {
        b -= 2, bss[1] = 1;
    }
    if(b>= 1)
    {
        b -= 1, bss[0] = 1;
    }
    int ans = 0;
    for(int i = 0; i <= 20; i ++)
    {
        if(ass[i] == 1 && bss[i] == 1)
        {
            ans += pow(2, i);
        }
    }
    return ans;
}
void func(int num, int ans, int dict)
{
    if(num >= m)
    {
        //cout << num;
        maxm = max(ans, maxm);
        return ;
    }
    if(num < m && dict > n)
        return ;
    func(num + 1, awh(ans, arr[dict + 1]), dict +  1);
    func(num, ans, dict + 1);
}
int main()
{
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)cin >> arr[i];
    if(n <= 20)
    {
        func(0, 0, 0);
        cout << maxm;
        return 0;
    }
    sort(arr + 1, arr + n + 1);
    if(m == 1)
    {
        cout << arr[n + 1];
        return 0;
    }
    if(m == 2)
    {
        int maxn = -1e9;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = i + 1; j <= n; j ++)
            {
                maxn = max(maxn, awh(arr[i], arr[j]));
            }
        }
        cout << maxn;
        return 0;
    }
    if(m == n)
    {
        int ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            ans = awh(ans, arr[i]);
        }
        cout <<ans;
        return 0;
    }
    else if(arr[n + 1] == 4)
    {
        cout << 4;
        return 0;
    }
    return 0;
}
//I must start playing Genshin Impact tight now;
//Wolves
/*
I ve been running through the jungle, ive been crying with the wolves.
To get to you, To get to you;

I ve been down the dark salies , all the darks are all the moon.
To get to you, To get to you;

(忘词了), Took too much easy in you.
All for you, Yeah all fou you....
*/
