#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005];
int b[200005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n, m, maxn = -1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[1];
    }
    long long M = m;
    for(int i = 1;i <= n;i++)
    {
        m = M;
        long long cnt = 0;
        for(int j = i;j >= 1;j--)
        {
            if(m >= b[i]-b[j])
            {
                m -= b[i]-b[j];
                cnt++;
                //cout << m << " " <<cnt <<" ";
            }
            else
            {

                break;
            }
        }
        //cout <<endl;
        maxn = max(maxn, cnt);
    }
    cout << maxn;
}
