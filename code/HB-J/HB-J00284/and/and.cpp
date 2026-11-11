#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;

int n , m , a[N];

int ans;//final answer

int count1(int x)
{
    int cnt = 0;
    while(x)
    {
        x = x & (x - 1);
        cnt++;
    }
    return cnt;
}

bool cmp(int x , int y)
{
    int cx = count1(x) , cy = count1(y);
    if(cx != cy) return cx > cy;//number of "1"
    return x > y;//length
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d", &n , &m);
    for(int i = 1 ; i <= n ; i ++)
    {
        scanf("%d",&a[i]);
    }
    // sort(a + 1 , a + 1 + n , cmp);
    for(int i = 1 ; i <= m ; i ++)
    {
        for(int j = 2 ; j <= n ; j ++)//a[1] is the best
        {
            if(cmp(a[j] , a[1])) 
            {
                swap(a[j] , a[1]);
            }
        }
        if(i == 1)
        {
            ans = a[1];
        }
        else
        {
            ans = ans & a[1];
        }
        swap(a[1] , a[n]);
        n--;
    }
    cout << ans;
    return 0;
}