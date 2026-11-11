#include <bits/stdc++.h>

using namespace std;

int n, a[200005];
char c[200005];
string sa, sb;

int main()
{
    freopen("string.in", "r",stdin );
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] >> c[i];
        for(int j = 1 ; j <= a[i] ; j++)
        {
            sa += c[i];
        }
    }
    int l1 = sa.size();
    int bb = 0;
    int cc = 0;
    if(l1 % 2 == 0 )
    {
        bb = l1 / 2 - 1;
        //aabb
        for(int i = 0 ; i <= bb ; i++)
        {
            sb += sa[i];
        }
        int aaa = bb + 1;
        for(int i = bb ; i >= 0 ; i--)
        {
            sb += sa[i];
            if(sa[i] != sa[aaa])
            {
                cc++;
            }
            aaa++;
        }
       // cout << sb;
    }
    else
    {
        //aabbc   aaaaa    aaa
        bb = l1 / 2 - 1;
        for(int i = 0 ; i <= bb ; i++)
        {
            sb += sa[i];
        }
        int aaa = bb + 2;
        sb += sa[bb + 1];
        for(int i = bb ; i >= 0 ; i--)
        {
            sb += sa[i];
            if(sa[i] != sa[aaa])
            {
                cc++;
            }
            aaa++;
        }
        //cout << sb;
    }
    cout << cc;




    return 0;
}
