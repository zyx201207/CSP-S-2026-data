#include <iostream>
using namespace std;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int k,m,n;cin >> m >> n;
int D[n + 100];
int a[n + 100];int I[m + 100];
int top = 0,pos[m + 100],cnt[m + 100];
for (int i = 0;i < m + 100;i++){I[i] = 0;cnt[i] = 0;pos[i] = -1;}
for (int i = 0;i < n + 100;i++){D[i] = -1;a[i] = 0;}
for (int i = 1;i <= n;i++){cin >> a[i];}
for (int i = 1;i <= n;i++)
{
for (int j = i;j <= n;j++)
{
k = a[j];
if (!I[k]){D[top] = k;top++;I[k] = 1;pos[k] = top - 1;}
if (I[k])
{
for (int r = pos[k];r < top;r++)
{
I[D[r]] = 0;pos[D[r]] = -1;D[r] = -1;top--;
}
D[top] = k;top++;
}
}
for (int r = 1;r <= m;r++)
{
cnt[r] += I[r];
}
}
for (int i = 1;i <= m;i++){cout << cnt[i] << " ";}
return 0;
}