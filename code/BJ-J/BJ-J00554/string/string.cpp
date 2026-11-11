#include <bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    char op;
};

node a[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].num >> a[i].op;
    }
    int i = 1;
    int j = n;
    long long sum = 0;
    while(i < j)
    {
        if(a[i].op != a[j].op)
        {
            if(a[i].num > a[j].num)
            {
                sum += a[j].num;
                a[i].num -= a[j].num;
                j--;
            }
            else if(a[i].num < a[j].num)
            {
                sum += a[i].num;
                a[j].num -= a[i].num;
                i++;
            }
            else if(a[i].num == a[j].num)
            {
                sum += a[i].num;
                i++;
                j--;
            }
        }
        else if(a[i].op == a[j].op)
        {
            if(a[i].num > a[j].num)
            {
                a[i].num -= a[j].num;
                j--;
            }
            else if(a[j].num > a[i].num)
            {
                a[j].num -= a[i].num;
                i++;
            }
            else if(a[j].num == a[i].num)
            {
                i++;
                j--;
            }
        }
    }
    cout << sum << "\n";
    return 0;
}