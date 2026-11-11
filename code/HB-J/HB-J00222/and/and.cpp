#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,maxn1 = 0;
    cin >> n >> m;
    long long num[n + 5] = {0},er[n + 5] = 0;
    for (long long i = 1;i <= n;i++)
        {
            cin >> num[i];
            if (num[i] > maxn1)
            {
                maxn1 = num[i];
            }
        //long long bei = 1,now = 1;
        //while (num[i] > bei)
        //{
        //    now *= 10;
        //    bei *= 2;
        //}
        //bei /= 2;
        //while(a == 0)
        //{
        //    if (a > bei)
        //    {
        //       er[i] += now;
        //       a -= bei;
        //  }
        //    bei /= 2;
        //    now /= 10;
        //}

    if (m = 1)
    {
        for (long long i = 1;i <= n;i++)
        {
            cout << maxn1;
    if (m = n)
    {

        for(int i = 1;i < n;i++)
        {
            long long a = er[i],b = er[i + 1];
            long long bei = 1,now = 1;
            bool ao = false,bo = false;
            while (a > bei && b > bei)
            {
                now *= 10;
                bei *= 2;
            }
            bei /= 2;
            while(a != 0 && b != 0)
            {
                if (a > bei)
                {
                    a -= bei;
                    ao = true;
                }
                if (b > bei)
                {
                    b -= bei;
                    bo = true;
                }
                if (ao && bo)
                {
                    er[i + 1] += now;
                }
                bei /= 2;
                now /= 10;
            }
        }
        cout << e[n];
    }
    if (m = n - 1)
    {
        long long maxn2 = 0
        for(int i = 1;i < n;i++)
        {
            for(int j = 1;j < n;j++)
            {
                long long a = er[i],b = er[i + 1];
                if(j == i + 1)
                {
                    er[i+1] = er[i];
                    continue;
                }
                long long bei = 1,now = 1;
                bool ao = false,bo = false;
                while (a > bei && b > bei)
                {
                    now *= 10;
                    bei *= 2;
                }
                bei /= 2;
                while(a != 0 && b != 0)
                {
                    if (a > bei)
                    {
                        a -= bei;
                        ao = true;
                    }
                    if (b > bei)
                    {
                        b -= bei;
                        bo = true;
                    }
                    if (ao && bo)
                    {
                        er[i + 1] += now;
                    }
                    bei /= 2;
                    now /= 10;
                }
            }
            if (er[n] > maxn2)
            {

                maxn2 = er[n];
            }
        }
        cout << maxn2;
    }
}

