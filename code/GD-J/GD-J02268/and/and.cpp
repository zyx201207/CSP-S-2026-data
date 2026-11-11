#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    //!!!Dont forget remove //
    //freopen("xxx.in", "r", stdin);
    //freopen("xxx.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    int mmaxx=0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        mmaxx = max(mmaxx, a[i]);
    }
    int ans = 0;
    if(m==2){
        for (int f = 0; f < n-1; f++)
        {
            for (int g = f+1; g < n; g++)
            {
                ans = max(a[f] & a[g], ans);
            }
        }
        cout << ans;
    }
    else if (m == 1)
    {
        cout << mmaxx;
    }
    else if(m==n){
        ans = a[0];
        for (int i = 1; i < n; i++)
        {
            ans = ans & a[i];
        }
        cout << ans;
    }
    else if(m==3){
        for (int f = 0; f < n-2; f++)
        {
            for (int g = f+1; g < n-1; g++)
            {
                for (int u = g+1; u < n; u++){
                    ans = max(a[f] & a[g]&a[u], ans);
                }

            }
        }
        cout << ans;
    }
    else if (m == 4)
    {
        for (int f = 0; f < n-3; f++)
        {
            for (int g = f; g < n-2; g++)
            {
                for (int u = g; u < n-1; u++)
                {
                    for (int p = u; p < n; p++)
                    {
                        ans = max(a[f] & a[g] & a[u] & a[p], ans);
                    }
                }
            }
        }
        cout << ans;
    }
    else if (m == 5)
    {
        for (int f = 0; f < n - 4; f++)
        {
            for (int g = f; g < n - 3; g++)
            {
                for (int u = g; u < n - 2; u++)
                {
                    for (int p = u; p < n-1; p++)
                    {
                        for (int l = p; l < n;l++){
                            ans = max(a[f] & a[g] & a[u] & a[p]&a[l], ans);
                        }

                    }
                }
            }
        }
        cout << ans;
    }
    else if (m == 6)
    {
        for (int f = 0; f < n - 5; f++)
        {
            for (int g = f; g < n - 4; g++)
            {
                for (int u = g; u < n - 3; u++)
                {
                    for (int p = u; p < n - 2; p++)
                    {
                        for (int l = p; l < n-1; l++)
                        {
                            for (int l1 = l; l1 < n;l1++){
                                ans = max(a[f] & a[g] & a[u] & a[p] & a[l]&a[l1], ans);
                            }

                        }
                    }
                }
            }
        }
        cout << ans;
    }

    return 0;
}
