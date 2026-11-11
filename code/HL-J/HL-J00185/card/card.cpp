#include<bits/stdc++.h>
using namespace std;
int n ,m, a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int x = a[i];
        for(int j = 1;j <= i;j++)
        {
            if(a[j] = x)
            {
                for(int q = j;q <= n;q++)
                {
                    a[q-j+i] = a[q];
                }
            }
        }
    }
    return 0;
}
