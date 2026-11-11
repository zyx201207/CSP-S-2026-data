#include <bits/stdc++.h>
using namespace std ;

const int N = 5 * 1e5 + 10 ;

int n , ans = 1;
long long m , a[N] , cha[N];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld", &n , &m);
    for(int i = 1 ; i <= n ; i ++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1 , a + 1 + n);
    for(int i = 1 ; i < n ; i ++)
    {
        cha[i] = a[i + 1] - a[i];
    }
    // if(n <= 16)
    // {
    //     for(int i = 1 ; i <= n ; i++)
    //     {
    //         int sum = 0;//cao zuo ge shu
    //         long long cnt = 0;//cao zuo ci shu
    //         // cout << a[i]; 
    //         int j;
    //         for(j = i ; cnt < m && j <= n; j ++)
    //         {
    //             long long t = cha[j] * (j-i+1);
    //             if(m - cnt >= t)//bu shu hai gou
    //             {
    //                 cnt += t;
    //                 sum ++;
    //             }
    //         }j--;
    //         int add = 0;
    //         for(int k = j + 1; k <= n ; k ++)
    //         {
    //             if(a[k] == a[k-1])add++;
    //         }
    //         sum += add;
    //         //cout << " sum = " << sum << endl;
    //         ans = min(n,max(ans , sum));
    //     }
    //     printf("%d",ans);
    // }
    // else
    // {
        int add = 0 , cnt = 0;
        for(int i = 2 ; i <= n ; i ++)
        {
            if(a[i] == a[i-1])
            {
                cnt++;
                add = max(add , cnt);
            }
            else 
            {
                cnt = 0;
            }
        }
        int f = a[2] - a[1];
        // cout <<"f = " << f << endl;
        for(int i = 2;i <= n;i ++)
        {
            if(f + f * i < m)
            {
                ans = i;
                f += f * i;
            }
            else break;
        }
        ans ++;
        ans += add;
        ans = min(n , ans);
        printf("%d",ans);
    // }
    return 0;
}