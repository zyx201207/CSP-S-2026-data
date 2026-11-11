#include<bits/stdc++.h>
using namespace std;
long long a[51000000];
long long a1[51000000];
long long vis[51000000];
long long cnt[51000000];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    long long n , m , js = 0;
    cin >> n >> m;
    long long n1 = n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n1 ; i++)
    {
        a1[i] = a[i];
        vis[a[i]]++;
        if(vis[a[i]] > 1)
        {
			for(int i = 1 ; i <= n ; i++)
			{
				a[i] = 0;
			}
            n1 -= i;
            i = 1;
        }
        if(!(n1 > 0) || i == n1)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(a1[i] == i)
                {
                    cnt[i]++;
                }
                js++;
            }
            n1 = n - js;
        }
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
