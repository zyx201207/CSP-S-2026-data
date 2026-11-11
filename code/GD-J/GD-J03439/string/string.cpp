#include<bits/stdc++.h>
using namespace std;
struct ac
{
    int ai;
    char ci;
}a[200010];
long long cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i].ai >> a[i].ci;
    }
    int l = 1,r = n;
    while(l<r)
    {
        if(a[l].ai>a[r].ai)
        {
            if(a[l].ci!=a[r].ci)
            {
                cnt += a[r].ai;
                a[l].ai -= a[r].ai;
            }
            else
            {
                a[l].ai -= a[r].ai;
            }
            r--;
        }
        else if(a[l].ai<a[r].ai)
        {
            if(a[l].ci!=a[r].ci)
            {
                cnt += a[l].ai;
                a[r].ai -= a[l].ai;
            }
            else
            {
                a[r].ai -= a[l].ai;
            }
            l++;
        }
        else
        {
            if(a[l].ci!=a[r].ci)
            {
                cnt += a[l].ai;
            }
            l++;
            r--;
        }
    }
    cout << cnt;
    return 0;
}
