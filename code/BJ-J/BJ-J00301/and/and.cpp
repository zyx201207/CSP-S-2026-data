#include<bits/stdc++.h>
#define int long long
using namespace std;

int er(int x)
{
    int num = 0;
    int wei = 1;
    stack<int> n;
    while (x != 0)
    {
        n.push(x % 2);
        x /=  2;
    }
    while(!n.empty())
    {
        num += n.top() * wei;
        wei *= 10;
        n.pop();
    }
    return num;
}
int erander(int x, int y)
{
    int num = 0;
    int wei = 1;
    stack<int> n;
    while(x != 0 || y != 0)
    {
        int xm = x % 10;
        int ym = y % 10;
        if(ym == 1 && xm == 1)
        {
            n.push(1);
        }
        else
        {
            n.push(0);
        }
        x /= 10;
        y /= 10;
    }
    while(!n.empty())
    {
        num += n.top() * wei;
        wei *= 10;
        n.pop();
    }
    return num;
}
int ertoten(int h)
{
    int num = 0;
    int wei = 0;
    while(h != 0)
    {
        int er = 1;
        int hm = h%10;
        for(int i = 1; i <= wei; i++)
        {
            er *= 2;
        }
        num += er * hm;
        h /= 10;
        wei ++;
    }
    return num;
}
bool minn(int a, int b)
{
    return a < b;
}
signed main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n, m;
    cin >> n >> m;
    int num = 0;
    vector<int> a;
    for(int i = 1; i <= n; i++)
    {
        int h; cin >> h;
        a.push_back(er(h));
    }
    sort(a.begin() , a.end() , minn);
    for(int i = 0; i < m; i++)
    {
        num = erander(num , a[i]);
    }
    cout << ertoten(num);
    return 0;
}
