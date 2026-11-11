#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;

long long L = 0, n;

long long ans = 0;//final answer

struct node{
    int ai;
    char ci;
}s[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld", &n);//cout << n << endl;
    for(int i = 1 ; i <= n ; i ++)//input
    {
        scanf("%d %c" , &s[i].ai , &s[i].ci);
        //cin >> s[i].ai >> s[i].ci;
        L += s[i].ai;
    }
    long long l = 1 , r = n;
    while(l < r)//~fenkuai
    {
        if(s[l].ci == s[r].ci)
        {
            if(s[l].ai < s[r].ai)
            {
                s[r].ai -= s[l].ai;
                l ++;
            }
            else if(s[l].ai == s[r].ai)
            {
                l ++;
                r --;
            }
            else
            {
                s[l].ai -= s[r].ai;
                r --;
            }
        }
        else
        {
            if(s[l].ai < s[r].ai)
            {
                ans += s[l].ai;
                s[r].ai -= s[l].ai;
                l ++;
            }
            else if(s[l].ai == s[r].ai)
            {
                ans += s[l].ai;
                l ++;
                r --;
            }
            else
            {
                ans += s[r].ai;
                s[l].ai -= s[r].ai;
                r --;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}