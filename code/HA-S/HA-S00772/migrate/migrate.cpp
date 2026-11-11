 #include <bits/stdc++.h>
using namespace std;
inline long long read()
{
long long res = 0;
char ch = getchar();
bool tag = 0;
while ((ch < '0' || ch > '9') && ch != '-')
ch = getchar();
if (ch == '-')
{
tag = 1;
ch = getchar();
}
while (ch >= '0' && ch <= '9')
{
res = (res << 3) + (res << 1) + ch - '0';
ch = getchar();
}
if (tag) return -res;
return res;
}
void write(long long x)
{
if (x < 0)
{
x = -x;
putchar('-');
}
if (x >= 10) write(x/10);
putchar(x%10+'0');
}
const int N = 2000006;
int op,T,n,pre[N],suf[N],fst[N],lst[N];
int sl[N],sr[N];
long long d,a[N],b[N],ans;
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
op = read(), T = read();
while (T--)
{
ans = 0;
n = read(), d = read();
for (int i=1;i<=n;i++) 
pre[i] = suf[i] = -1;
for (int i=1;i<=n;i++) 
a[i] = read();
for (int i=1;i<n;i++) 
b[i] = a[i+1] - a[i];
for (int i=1,j=1;i<=n;i++)
{
while (j < i && a[i]-a[j] > d) ++j;
fst[i] = j;
}
for (int i=n,j=n;i>=1;i--)
{
while (j > i && a[j]-a[i] > d) --j;
lst[i] = j;
}
pre[1] = 0, suf[n] = 0;
for (int i=2;i<=n;i++)
pre[i] = pre[fst[i]] + 1;
for (int i=n-1;i>=1;i--)
suf[i] = suf[lst[i]] + 1;
for (int u=1;u<=n;u++)
{
for (int v=u+1;v<=n;v++)
{
int x = u;
long long res = 0;
while (x != lst[x] && lst[x] < v)
{
res += lst[x];
x = lst[x];
}
if (x == lst[x]) break;
x = v;
while (fst[x] > u)
{
res -= fst[x];
x = fst[x];
}
if (res == 1) ans++;
}
}
write(ans);
puts("");
}
return 0;
}
 
                        
