#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long a[N];
int b[N];

int n, flag;

long long k = 0, l = 1, r = 0, lm = 0, rm = 0;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    long long m = 0, mid = 0, len = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        char x;
        cin >> x;
        b[i] = int(x - 'a') + 1;
        k += a[i];
        if(b[i] == b[i - 1])
        {
            a[i - 1] += a[i];
            a[i] = 0;
            b[i] = 0;
            i--;
            n--;
            //cout << i << "#" << n << endl;
        }
    }

    /*
    cout << endl << endl;
    cout << n << endl;
    for(int i = 1;i <= n;i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    for(int i = 1;i <= n;i++)
    {
        cout << b[i] << ' ';
    }
    cout << endl << endl;
    */

    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    m = (k + 1) / 2;
    mid = m;
    len = k;
    //cout << m << "###" << endl;
    r = k;
    for(int i = 1;i <= n;i++)
    {
        m -= a[i];
        lm += a[i];
        //cout << lm << " ## " << i << " " << m << endl;
        if(m <= 0)
        {
            flag = i;
            lm = lm - a[i];
            //cout << lm << " ### " << flag << endl;
            break;
        }
    }
    rm = lm + a[flag] + 1;
    k = (k + 1) / 2;
    int i = 1, j = n;
    long long x = 0, y;
    //cout << k << " #1" << endl;
    if(len & 1)
    {
        k -= min(rm - mid, mid - lm);
    }
    else
    {
        k -= min(rm - mid - 1, mid - lm);
    }
    /*cout << k << " #2 " << lm << " " << mid << " " << rm << " flag: " << flag << " lr "
     << lm << " " << rm << " min " << rm - mid - 1 << " " << mid - lm + 1 << endl; */
    lm += 1;
    rm -= 1;
    while(l < lm || r > rm)
    {
        if(b[i] == b[j])
        {
            k -= min(a[i], a[j]);
            //cout << "%%%" << endl;
        }
        if(a[i] <= a[j]) {x = a[i];y = 1;}
        else {x = a[j];y = 0;}
        //cout << l << " " << r << " # " << i << " " << j << " # " << k << " " << x << endl;
        if(l < lm)
        {
            l += x;
            if(y)
            {
                i++;
            }
            else
            {
                a[i] -= x;
            }
        }
        if(r > rm)
        {
            r -= x;
            if(!y)
            {
                j--;
            }
            else
            {
                a[j] -= x;
            }
        }
        //return 0;
    }
    cout << k << endl;
    return 0;
}