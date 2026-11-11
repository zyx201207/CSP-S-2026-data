#include <bits/stdc++.h>
using namespace std;

const int M = 3 * 1e5 + 10 , N = 5 * 1e5 + 10;

int n , m;
int a[N];
int bigbook[M];
int book[M];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d" , &n , &m);
    for(int i = 1 ; i <= n ; i ++)
    {
        scanf("%d" , &a[i]);
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int i = 1 ; i <= m ; i ++)
        {
            book[i] = 0;
        }
        int pos = 1;
        for(int j = i ; j <= n ; j ++)
        {
            if(book[a[j]])pos = j;
            book[a[j]] ++;
        }
        for(int j = pos ; j <= n ; j ++)
        {
            bigbook[a[j]] ++;
        }
    }
    for(int i = 1 ; i <= m ; i ++)
    {
        printf("%d ", bigbook[i]);
    }
    return 0;
}