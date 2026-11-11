#include<bits/stdc++.h>
long long n;
long long a[200010];
char c[200010];
char lc,rc;
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
    }

    long long li = 1,ri = n;
    long long ans = 0;
    while(li <= ri)
    {

        if(c[li] != c[ri])
        {
            if(a[li] < a[ri])
            {
                ans += a[li];
                a[ri] -= a[li];
                li++;
            }
            else if(a[li] > a[ri])
            {
                ans += a[ri];
                a[li] -= a[ri];
                ri--;
            }
            else if(a[li] == a[ri])
            {
                ans += a[li];
                li++;
                ri--;
            }

        }
        else
        {
            if(a[li] < a[ri])
            {
                a[ri] -= a[li];
                li++;
            }
            else if(a[li] > a[ri])
            {
                a[li] -= a[ri];
                ri--;
            }
            else if(a[li] == a[ri])
            {
                li++;
                ri--;
            }
        }
    }
    cout <<ans << endl;
    return 0;
}
