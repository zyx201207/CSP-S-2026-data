#include<bits/stdc++.h>
using namespace std;
int n, m;
long long maxx = -1;
long long a[200005];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if(m == 1)
    {
        cout << a[1];
        return 0;
    }
    else if(m == 2)
    {
        for(int i = 1; i < n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                if((a[i] & a[j]) >= maxx)
                    maxx = (a[i] & a[j]);
            }
        }
        cout << maxx;
        return 0;
    }
    else if(m == 3)
    {
        for(int i = 1; i < n - 1; i++)
        {
            for(int j = i; j < n; j++)
            {
                for(int k = j; k <= n; k++)
                {
                    if(((a[i] & a[j]) & a[k]) >= maxx)
                        maxx = ((a[i] & a[j]) & a[k]);
                }
            }
        }
        cout << maxx;
        return 0;
    }
    else if(m == 4)
    {
        for(int i = 1; i < n - 2; i++)
        {
            for(int j = i; j < n - 1; j++)
            {
                for(int k = j; k < n; k++)
                {
                    for(int l = k; l <= n; l++)
                        if((((a[i] & a[j]) & a[k]) & a[l]) >= maxx)
                            maxx = (((a[i] & a[j]) & a[k]) & a[l]);
                }
            }
        }
        cout << maxx;
        return 0;
    }
    else if(m == 5)
    {
        for(int i = 1; i < n - 3; i++)
        {
            for(int j = i; j < n - 2; j++)
            {
                for(int k = j; k < n - 1; k++)
                {
                    for(int l = k; l < n; l++)
                    {
                        for(int r = 1; r <= n; r++)
                            if(((((a[i] & a[j]) & a[k]) & a[l]) & a[r]) >= maxx)
                                maxx = ((((a[i] & a[j]) & a[k]) & a[l]) & a[r]);
                    }
                }
            }
        }
        cout << maxx;
        return 0;
    }
    else
    {
        for(int i = n; i > 1; i++)
            if((a[i] & a[i - 1]) != 0)
            {
                cout << (a[i] & a[i - 1]);
                return 0;
            }
        cout << a[n - 1];
        return 0;
    }
    return 0;
}
