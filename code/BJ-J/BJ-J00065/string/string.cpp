#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
char c[1000005];
long long sum = 0,minn = INT_MAX,minn2 = INT_MAX;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    int cnt = 1,cmt = n;
    for(int i = 1;i<=n;i++)
    {
        if(c[cnt] == c[cmt])
        {
            minn = min(a[cnt],a[cmt]);
            a[cnt] -= minn;
            a[cmt] -= minn;
            if(a[cnt] == 0 && a[cmt] == 0)
            {
                cnt++;
                cmt--;
            }
            else if(a[cnt] == 0)
            {
                cnt++;
            }
            else
            {
                cmt--;
            }
        }
        else
        {
            minn2 = min(a[cnt],a[cmt]);
            sum += minn2;
            a[cnt] -= minn2;
            a[cmt] -= minn2;
            if(a[cnt] == 0 && a[cmt] == 0)
            {
                cnt++;
                cmt--;
            }
            else if(a[cnt] == 0)
            {
                cnt++;
            }
            else
            {
                cmt--;
            }
        }
        if(cnt == cmt)
        {
            break;
        }
    }
    cout << sum;
    return 0;
}
