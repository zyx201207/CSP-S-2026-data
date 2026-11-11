#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin >> n >> m;
for(int i = 1;i <= n;++i)
cin >> a[i];
for(int i = 1;i <= n;++i)
for(int j = 1 + i;j <= n;++j)
if(a[i] < a[j])
swap(a[i],a[j]);
cout << a[m];
return 0;
}