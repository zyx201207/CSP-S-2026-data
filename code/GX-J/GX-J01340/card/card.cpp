#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+1;

int n,m;

int a[maxn];
int b[maxn];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(m==1)
    {
        cout << n;
    }
    return 0;
}
