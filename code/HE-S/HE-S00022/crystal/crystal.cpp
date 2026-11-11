#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long lists[500005];//Start long long or to see god!
bool cmp(long long a,long long b)
{
    return a < b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long lost = 0,get_lost = 0;//still one step to AC.gif
    cin >> n >> m;
    for(long long i = 1;i <= n;i++)
    {
        cin >> lists[i];
    }
    sort(lists + 1,lists + 1 + n,cmp);
    long long l = 1,r = n;//two_divide.png
    while(l <= r)
    {
        bool get_it = false;
        lost = 0;
        long long mid = (l + r) / 2,cost = 0;
        for(long long i = mid;i >= 1;i--)
        {
            cost += lists[mid] - lists[i];
            if(cost > m)
            {
                break;
            }
            lost++;
        }
        if(cost > m)
        {
            r = mid - 1;
        }
        else if(cost < m)
        {
            l = mid + 1;
        }
        else if(cost == m)
        {
            //get!
            while(lists[mid] == lists[mid + 1])
            {
                mid++;
            }
            get_lost = max(get_lost,mid);
            get_it = true;
            break;
        }
        if(get_it)
        {
            break;
        }
        while(lists[mid] == lists[mid + 1])
        {
            lost++;
            mid++;
        }
        get_lost = max(get_lost,lost);
    }
    cout << get_lost;//4 -> 315275
    fclose(stdin);
    fclose(stdout);
    return 0;
}
