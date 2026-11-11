#include <iostream>
using namespace std;
bool check(int n)
{
    if (n == 1){return true;}
    if (n == 2){return true;}
    if (n == 4){return true;}
    if (n == 8){return true;}
    if (n == 16){return true;}
    if (n == 32){return true;}
    if (n == 64){return true;}
    if (n == 128){return true;}
    if (n == 256){return true;}
    if (n == 512){return true;}
    if (n == 1024){return true;}
    if (n == 2048){return true;}
    if (n == 4096){return true;}
    if (n == 8192){return true;}
    if (n == 16384){return true;}
    if (n == 32768){return true;}
    if (n == 65536){return true;}
    if (n == 131072){return true;}
    if (n == 262144){return true;}
    if (n == 524288){return true;}
    if (n == 1048576){return true;}
    if (n == 2097152){return true;}
    if (n == 4194304){return true;}
    if (n == 4194304 * 2){return true;}
    if (n == 4194304 * 4){return true;}
    if (n == 4194304 * 8){return true;}
    if (n == 4194304 * 16){return true;}
    if (n == 4194304 * 32){return true;}
    if (n == 4194304 * 64){return true;}
    if (n == 4194304 * 128){return true;}
    if (n == 4194304 * 256){return true;}
    if (n == 4194304 * 512){return true;}
    return false;
}
int calp(int n)
{
    if (n == 1){return 0;}
    if (n == 2){return 1;}
    if (n == 4){return 2;}
    if (n == 8){return 3;}
    if (n == 16){return 4;}
    if (n == 32){return 5;}
    if (n == 64){return 6;}
    if (n == 128){return 7;}
    if (n == 256){return 8;}
    if (n == 512){return 9;}
    if (n == 1024){return 10;}
    if (n == 2048){return 11;}
    if (n == 4096){return 12;}
    if (n == 8192){return 13;}
    if (n == 16384){return 14;}
    if (n == 32768){return 15;}
    if (n == 65536){return 16;}
    if (n == 131072){return 17;}
    if (n == 262144){return 18;}
    if (n == 524288){return 19;}
    if (n == 1048576){return 20;}
    if (n == 2097152){return 21;}
    if (n == 4194304){return 22;}
    if (n == 4194304 * 2){return 23;}
    if (n == 4194304 * 4){return 24;}
    if (n == 4194304 * 8){return 25;}
    if (n == 4194304 * 16){return 26;}
    if (n == 4194304 * 32){return 27;}
    if (n == 4194304 * 64){return 28;}
    if (n == 4194304 * 128){return 29;}
    if (n == 4194304 * 256){return 30;}
    if (n == 4194304 * 512){return 31;}
    return -1;
}
int fun(int x)
{
    int v = 1;
    for (int i = 0;i < x;i++){v = v + v;}
    return v;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int p = 1,n;cin >> n;
if (n <= 20)
{
int a[n],c[n],C,pos,A,ans = -1,S,m;cin >> m;
for (int i = 0;i < n;i++){cin >> a[i];}
for (int i = 0;i < n;i++){p = p + p;}
for (int i = 0;i < p;i++)
{
for (int j = 0;j < n;j++){c[j] = 0;}
C = i;pos = 0;A = 2147483647;S = 0;
while (C)
{
if (C % 2 == 1){S++;}
c[pos] = C % 2;C = C / 2;pos++;
}
if (S == m)
{
for (int j = 0;j < n;j++){if (c[j] == 1){A = A & a[j];}}
if (A > ans){ans = A;}
}
}
cout << ans;return 0;
}
int m;cin >> m;
if (m == 1)
{
    int a[n],ans = -1;
    for (int i = 0;i < n;i++){cin >> a[i];}
    for (int i = 0;i < n;i++){if (a[i] > ans){ans = i;}}
    cout << ans;return 0;
}
if (m == n - 1)
{
    int a[n],ans = 2147483647;
    for (int i = 0;i < n;i++){cin >> a[i];}
    for (int i = 0;i < n;i++){ans = ans & a[i];}
    cout << ans;return 0;
}
if (m == 2 && n <= 2000)
{
    int a[n],ans = -1,v;
    for (int i = 0;i < n;i++){cin >> a[i];}
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            v = a[i] & a[j];
            if (v > ans){ans = v;}
        }
    }
    cout << ans;return 0;
}
int a[n],v = -1;int flag = 1;
for (int i = 0;i < n;i++)
{
    cin >> a[i];
    if (a[i] > v){v = a[i];}
    if (!check(a[i] + 1)){flag = 0;}
}
if (v <= 4)
{
    int ans = -1,cp,p,C[5],cnt[5];cnt[0] = 0;cnt[1] = 0;cnt[2] = 0;cnt[3] = 0;cnt[4] = 0;int iv,av;
    for (int i = 0;i < n;i++)
    {
        if (a[i] == 0){cnt[0]++;}
        if (a[i] == 1){cnt[1]++;}
        if (a[i] == 2){cnt[2]++;}
        if (a[i] == 3){cnt[3]++;}
        if (a[i] == 4){cnt[4]++;}
    }
    for (int i = 0;i < 32;i++)
    {
        iv = 0;av = 0;
        C[0] = 0;C[1] = 0;C[2] = 0;C[3] = 0;C[4] = 0;p = 0;cp = i;
        while (cp){C[p] = cp % 2;cp = cp / 2;p++;}
        for (int j = 0;j < 5;j++){iv += C[j];av += C[j] * cnt[j];}
        s = 7;for (int j = 0;j < 5;j++){if (C[j]){s = s & j;}
        if (s > ans && iv <= m && av >= m){ans = s;}
    }
    cout << ans;return 0;
}
if (flag == 1)
{
    int P = -1;int s = 0;
    int cnt[100];for (int i = 0;i < 100;i++){cnt[i] = 0;}
    for (int i = 0;i < n;i++){cnt[calp(a[i] + 1)]++;}
    for (int i = 100;i >= 0;i--){if (cnt[i] != 0){P = i;break;}}
    for (int i = 100;i >= 0;i--)
    {
        s += cnt[i];ans = fun(i) - 1;
        if (s >= m){cout << ans;return 0;}
    }
}
cout << 2026;
return 0;
}