#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

static constexpr int N = 5e5 + 5;
using std::vector;
using std::pair;

long long n;
bool equal_to_i = true;
bool greater_than_3 = true;
bool equal_d = true;
long long diff[N];
long long m;
long long d;
long long ans;
vector<int> a;

inline pair<long,long> solve(long long x)
{
    long long val = 0;
    long long num = 0;
    for(int i = 0;i <= x;i++)
    {
        val += a[x] - a[i];
    }
    for(int i = 0;i <= x;i++)
    {
        if(val <= m)
        {
            num = std::max(num,x - i + 1);
        }
    }

    return {val,num};
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>n>>m;
    int p1,p2,q2;
    a.resize(n);
    if(n == 1)
    {
        std::cin>>p1;
        std::cout<<1;
        return 0;
    }
    else if(n == 2)
    {
        std::cin>>p2>>q2;
        if(q2 - p2 > m)
        {
            std::cout<<1;
        }
        else std::cout<<2;
        return 0;
    }
    for(int i = 0;i < n;i++)
    {
        std::cin>>a[i];
    }
    std::sort(a.begin(),a.end());
    for(int i = 0;i < n - 2;i++)
    {
        if(a[i + 1] - a[i] != a[i + 2] - a[i + 1]) equal_d = false;
    }
    if(equal_d)
    {
        d = a[1] - a[0];
        long long k = floor((1.0 + sqrt(1.0 + 8.0 * m / d)) / 2.0);
        std::cout<<std::min(k,n);
        return 0;
    }

    ans = 0;
    long long cn;

    int left = 0,right = a.size();
    while(left <= right)
    {
        long long mid = (left + right) >> 1;
        /*for(int j = mid;j < n;j++)
        {
            if(a[j] == a[j + 1]) mid++;
            else break;
        }*/
        while(a[mid] == a[mid + 1])
        {
            mid++;
            /*if(a[mid] == a[mid + 1])
            {
                mid ++;
            }
            else break;*/
        }
        pair<long long,long long> cur = solve(mid);
        long long val = cur.first;
        long long num = cur.second;

        if(val <= m)
        {
            left = mid + 1;
            ans = std::max(ans,num);
        }
        else
        {
            right = mid - 1;
            ans = std::max(ans,num);
        }
    }
    std::cout<<ans;

    return 0;
}
