#include<bits/stdc++.h>
using namespace std;

int n,m,t,max1,max2,minx;
int a[200005],b[200005];
int k[2005][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];

        max2 = max(a[i],max2);
        if(max2 > max1)
        {
            int y = max2;
            max2 = max1;
            max1 = y;
        }
    }

    if(m == 1) cout << max1;
    if(m == 2) cout << (max1&max2);

    return 0;
}
