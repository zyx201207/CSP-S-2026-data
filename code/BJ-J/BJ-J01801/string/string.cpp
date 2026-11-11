#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,z = -1;
cin >> n;
for(int i = 1;i <= n;++i)
{
int x;
char y;
cin >> x >> y;
a[y - 'a' + 1] += x;
}
for(int i = 1;i <= 26;++i)
z = max(z,a[i]);
cout << z;
return 0;
}