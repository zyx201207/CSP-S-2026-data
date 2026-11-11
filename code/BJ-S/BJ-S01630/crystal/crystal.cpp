#include <iostream>
#include <algorithm>
using namespace std;
long long x[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long a, b;
    cin >> a >> b;
    for(int i=1; i<=a; i++)
    {
        cin >> x[i];
    }
    sort(x+1, x+a+1);
    long long ans2=0;
    for(int i=1; i<=a; i++)
    {
        long long sum=0;
        long long ans1=0;
        for(int j=1; j<=i; j++)
        {
            if((sum+x[i]-x[j])<=b)
            {
                sum=sum+x[i]-x[j];
                ans1++;
            }
            else
                break;
        }
        ans2=max(ans2, ans1);
    }
    cout << ans2;
    return 0;
}
